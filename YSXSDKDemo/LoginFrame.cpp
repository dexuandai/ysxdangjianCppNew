#include "stdafx.h"
#include "LoginFrame.h"
#include "MainWnd.h"


#pragma region 字符串处理

//unicode 转为 ascii 
std::string WideByte2AcsiCopy(const std::wstring wstrcode)
{
	int asciisize = ::WideCharToMultiByte(CP_OEMCP, 0, wstrcode.c_str(), -1, NULL, 0, NULL, NULL);
	if (asciisize == ERROR_NO_UNICODE_TRANSLATION)
	{
		throw std::exception("Invalid UTF-8 sequence.");
	}
	if (asciisize == 0)
	{
		throw std::exception("Error in conversion.");
	}
	std::vector<char> resultstring(asciisize);
	int convresult = ::WideCharToMultiByte(CP_OEMCP, 0, wstrcode.c_str(), -1, &resultstring[0], asciisize, NULL, NULL);
	if (convresult != asciisize)
	{
		throw std::exception("La falla!");
	}
	return std::string(&resultstring[0]);
}
#pragma endregion

CLoginFrame *m_pThis = NULL;

CLoginFrame::CLoginFrame()
{
	m_pThis = this;
}


CLoginFrame::~CLoginFrame()
{
}

DUI_BEGIN_MESSAGE_MAP(CLoginFrame, WindowImplBase)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_END_MESSAGE_MAP()


CDuiString CLoginFrame::GetSkinFolder()
{
	return _T("");
}

CDuiString CLoginFrame::GetSkinFile()
{
	return _T("homepage.xml");
}

void CLoginFrame::InitWindow()
{
	//最小和关闭
	m_pHomepageMinBtn = dynamic_cast<CButtonUI*>(m_pm.FindControl(_T("btn_homepage_min")));
	m_pHomepageCloseBtn = dynamic_cast<CButtonUI*>(m_pm.FindControl(_T("btn_homepage_close")));

	//左侧菜单
	m_pMeetingInstantBtn = dynamic_cast<CButtonUI*>(m_pm.FindControl(_T("btn_meeting_instant"))); 
	m_pMeetingJoinBtn = dynamic_cast<CButtonUI*>(m_pm.FindControl(_T("btn_meeting_join")));
	m_pMeetingAppointBtn = dynamic_cast<CButtonUI*>(m_pm.FindControl(_T("btn_meeting_appoint")));
	m_pMeetingListBtn = dynamic_cast<CButtonUI*>(m_pm.FindControl(_T("btn_meeting_list")));
	m_pMeetingContactBtn = dynamic_cast<CButtonUI*>(m_pm.FindControl(_T("btn_meeting_contact")));
	//左侧边栏显示
	m_LayoutSideMeetingInstant = static_cast<CHorizontalLayoutUI*>(m_pm.FindControl(_T("lay_side_meeting_instant")));
	m_LayoutSideMeetingJoin = static_cast<CHorizontalLayoutUI*>(m_pm.FindControl(_T("lay_side_meeting_join")));
	m_LayoutSideMeetingAppoint = static_cast<CHorizontalLayoutUI*>(m_pm.FindControl(_T("lay_side_meeting_appoint")));
	m_LayoutSideMeetingList = static_cast<CHorizontalLayoutUI*>(m_pm.FindControl(_T("lay_side_meeting_list")));
	m_LayoutSideMeetingContact = static_cast<CHorizontalLayoutUI*>(m_pm.FindControl(_T("lay_side_meeting_contact")));
	//右侧tab页显示
	m_LayoutTabMettingInstant = static_cast<CVerticalLayoutUI*>(m_pm.FindControl(_T("tab_instant_meeting")));
	m_LayoutTabMeetingJoin = static_cast<CVerticalLayoutUI*>(m_pm.FindControl(_T("tab_join_meeting")));
	m_LayoutTabMettingAppoint = static_cast<CVerticalLayoutUI*>(m_pm.FindControl(_T("tab_appoint_meeting")));
	m_LayoutTabMeetingList = static_cast<CVerticalLayoutUI*>(m_pm.FindControl(_T("tab_meeting_list")));
	m_LayoutTabMettingContact = static_cast<CVerticalLayoutUI*>(m_pm.FindControl(_T("tab_meeting_contact")));
	m_LayoutTabMettingContact_1 = static_cast<CVerticalLayoutUI*>(m_pm.FindControl(_T("tab_meeting_contact_1")));
	m_LayoutTabMettingContact_2 = static_cast<CVerticalLayoutUI*>(m_pm.FindControl(_T("tab_meeting_contact_2")));
	m_LayoutInstantPersonList = static_cast<CHorizontalLayoutUI*>(m_pm.FindControl(_T("show_instant_person_list")));
	m_LayoutAppointPersonList = static_cast<CHorizontalLayoutUI*>(m_pm.FindControl(_T("show_appoint_person_list")));
	//文本框
	m_EditInstantTopic = static_cast<CEditUI*>(m_pm.FindControl(_T("edit_InstantTopic")));
	m_EditAppointTopic = static_cast<CEditUI*>(m_pm.FindControl(_T("edit_AppointTopic")));
	m_EditAppointStartTime = static_cast<CEditUI*>(m_pm.FindControl(_T("edit_AppointStartTime")));
	m_EditAppointDuration = static_cast<CEditUI*>(m_pm.FindControl(_T("edit_AppointDuration")));
	m_EditMeetingNumber = static_cast<CEditUI*>(m_pm.FindControl(_T("edit_MeetingNumber")));
	m_EditInstantPerson = static_cast<CEditUI*>(m_pm.FindControl(_T("edit_InstantPerson")));
	//会议按钮
	m_pStartInstantBtn = dynamic_cast<CButtonUI*>(m_pm.FindControl(_T("btn_start_instant")));
	m_pJoinMeetingBtn = dynamic_cast<CButtonUI*>(m_pm.FindControl(_T("btn_join_meeting")));
	m_pAppointMeetingBtn = dynamic_cast<CButtonUI*>(m_pm.FindControl(_T("btn_appoint_meeting")));
	//其他按钮
	m_pInstantPersonBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("btn_instant_person")));
	m_pAppointPersonBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("btn_appoint_person")));
	m_pTestDepartmentBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("btn_test_department")));
	m_pTestDepartmentSelectorBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("btn_test_department_selector")));
	m_pSelectWjhBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("btn_wjh")));
	m_pSelectFssBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("btn_fss")));
	m_pSelectLxcBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("btn_lxc")));
	m_pSelectSksBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("btn_sks")));
	m_pSelectJxzBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("btn_jxz")));
	m_pSelectConfirm = static_cast<CButtonUI*>(m_pm.FindControl(_T("btn_contact_confirm")));
	//checkbox
	m_pSelectWjhCb = static_cast<CControlUI*>(m_pm.FindControl(_T("cb_wjh")));
	m_pSelectFssCb = static_cast<CControlUI*>(m_pm.FindControl(_T("cb_fss")));
	m_pSelectLxcCb = static_cast<CControlUI*>(m_pm.FindControl(_T("cb_lxc")));
	m_pSelectSksCb = static_cast<CControlUI*>(m_pm.FindControl(_T("cb_sks")));
	m_pSelectJxzCb = static_cast<CControlUI*>(m_pm.FindControl(_T("cb_jxz")));
}

LPCTSTR	CLoginFrame::GetWindowClassName() const
{
	return _T("DUILoginFrame");
}

UINT CLoginFrame::GetClassStyle() const
{
	return CS_DBLCLKS;
}

LRESULT CLoginFrame::MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled)
{
	return WindowImplBase::MessageHandler(uMsg, wParam, lParam, bHandled);
}

CControlUI* CLoginFrame::CreateControl(LPCTSTR pstrClass)
{
	return NULL;
}

void CLoginFrame::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		CDuiString strName = msg.pSender->GetName(); //获取按钮名称

		if (strName == _T("btn_homepage_min"))
		{
			SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
		if (strName == _T("btn_homepage_close"))
		{
			::MessageBox(NULL, L"退出程序", L"提示", MB_OK);
			Close(); //没有真正退出
			//PostQuitMessage(0);
			
		}

		//颜色转换成DWORD
		LPCTSTR colValWhite = _T("#FFFFFFFF");
		if (*colValWhite == _T('#')) colValWhite = ::CharNext(colValWhite);
		LPTSTR pstr1 = NULL;
		DWORD clrColorWhite = _tcstoul(colValWhite, &pstr1, 16);

		LPCTSTR colValMenu = _T("#FFEDF0F5");
		if (*colValMenu == _T('#')) colValMenu = ::CharNext(colValMenu);
		LPTSTR pstr2 = NULL;
		DWORD clrColorMenu = _tcstoul(colValMenu, &pstr2, 16);

		
		//点击侧边栏菜单
		if (strName == _T("btn_meeting_instant"))
		{
			m_LayoutSideMeetingInstant->SetBkColor(clrColorWhite);
			m_LayoutTabMettingInstant->SetVisible(true);

			m_LayoutSideMeetingJoin->SetBkColor(clrColorMenu);
			m_LayoutTabMeetingJoin->SetVisible(false);
			m_LayoutSideMeetingAppoint->SetBkColor(clrColorMenu);
			m_LayoutTabMettingAppoint->SetVisible(false);
			m_LayoutSideMeetingList->SetBkColor(clrColorMenu);
			m_LayoutTabMeetingList->SetVisible(false);
			m_LayoutSideMeetingContact->SetBkColor(clrColorMenu);
			m_LayoutTabMettingContact->SetVisible(false);
			m_LayoutTabMettingContact_1->SetVisible(false);
			m_LayoutTabMettingContact_2->SetVisible(false);
			m_pSelectWjhCb->SetVisible(false);
			m_pSelectFssCb->SetVisible(false);
			m_pSelectLxcCb->SetVisible(false);
			m_pSelectSksCb->SetVisible(false);
			m_pSelectJxzCb->SetVisible(false);
			m_LayoutInstantPersonList->SetVisible(false);
			m_LayoutAppointPersonList->SetVisible(false);
		}
		if (strName == _T("btn_meeting_join"))
		{
			m_LayoutSideMeetingJoin->SetBkColor(clrColorWhite);
			m_LayoutTabMeetingJoin->SetVisible(true);
			m_LayoutSideMeetingInstant->SetBkColor(clrColorMenu);
			m_LayoutTabMettingInstant->SetVisible(false);
			m_LayoutSideMeetingAppoint->SetBkColor(clrColorMenu);
			m_LayoutTabMettingAppoint->SetVisible(false);
			m_LayoutSideMeetingList->SetBkColor(clrColorMenu);
			m_LayoutTabMeetingList->SetVisible(false);
			m_LayoutSideMeetingContact->SetBkColor(clrColorMenu);
			m_LayoutTabMettingContact->SetVisible(false);
			m_LayoutTabMettingContact_1->SetVisible(false);
			m_LayoutTabMettingContact_2->SetVisible(false);
		}
		if (strName == _T("btn_meeting_appoint"))
		{
			m_LayoutSideMeetingJoin->SetBkColor(clrColorMenu);
			m_LayoutTabMeetingJoin->SetVisible(false);
			m_LayoutSideMeetingInstant->SetBkColor(clrColorMenu);
			m_LayoutTabMettingInstant->SetVisible(false);
			m_LayoutSideMeetingAppoint->SetBkColor(clrColorWhite);
			m_LayoutTabMettingAppoint->SetVisible(true);
			m_LayoutSideMeetingList->SetBkColor(clrColorMenu);
			m_LayoutTabMeetingList->SetVisible(false);
			m_LayoutSideMeetingContact->SetBkColor(clrColorMenu);
			m_LayoutTabMettingContact->SetVisible(false);
			m_LayoutInstantPersonList->SetVisible(false);
			m_LayoutAppointPersonList->SetVisible(false);
			m_LayoutTabMettingContact_1->SetVisible(false);
			m_LayoutTabMettingContact_2->SetVisible(false);
			m_pSelectWjhCb->SetVisible(false);
			m_pSelectFssCb->SetVisible(false);
			m_pSelectLxcCb->SetVisible(false);
			m_pSelectSksCb->SetVisible(false);
			m_pSelectJxzCb->SetVisible(false);
		}
		if (strName == _T("btn_meeting_list"))
		{
			m_LayoutSideMeetingJoin->SetBkColor(clrColorMenu);
			m_LayoutTabMeetingJoin->SetVisible(false);
			m_LayoutSideMeetingInstant->SetBkColor(clrColorMenu);
			m_LayoutTabMettingInstant->SetVisible(false);
			m_LayoutSideMeetingAppoint->SetBkColor(clrColorMenu);
			m_LayoutTabMettingAppoint->SetVisible(false);
			m_LayoutSideMeetingList->SetBkColor(clrColorWhite);
			m_LayoutTabMeetingList->SetVisible(true);
			m_LayoutSideMeetingContact->SetBkColor(clrColorMenu);
			m_LayoutTabMettingContact->SetVisible(false);
			m_LayoutTabMettingContact_1->SetVisible(false);
			m_LayoutTabMettingContact_2->SetVisible(false);
		}
		if (strName == _T("btn_meeting_contact"))
		{
			m_LayoutSideMeetingJoin->SetBkColor(clrColorMenu);
			m_LayoutTabMeetingJoin->SetVisible(false);
			m_LayoutSideMeetingInstant->SetBkColor(clrColorMenu);
			m_LayoutTabMettingInstant->SetVisible(false);
			m_LayoutSideMeetingAppoint->SetBkColor(clrColorMenu);
			m_LayoutTabMettingAppoint->SetVisible(false);
			m_LayoutSideMeetingList->SetBkColor(clrColorMenu);
			m_LayoutTabMeetingList->SetVisible(false);
			m_LayoutSideMeetingContact->SetBkColor(clrColorWhite);
			m_LayoutTabMettingContact->SetVisible(true);
			m_LayoutTabMettingContact_1->SetVisible(false);
			m_LayoutTabMettingContact_2->SetVisible(false);
			m_pSelectWjhCb->SetVisible(false);
			m_pSelectFssCb->SetVisible(false);
			m_pSelectLxcCb->SetVisible(false);
			m_pSelectSksCb->SetVisible(false);
			m_pSelectJxzCb->SetVisible(false);
		}
		if (strName == _T("btn_test_department"))
		{
			m_LayoutTabMettingContact->SetVisible(false);
			m_LayoutTabMettingContact_1->SetVisible(true);
		}
		if (strName == _T("btn_test_department_selector"))
		{
			m_LayoutTabMettingContact->SetVisible(false);
			m_LayoutTabMettingContact_2->SetVisible(true);
		}
		if (strName == _T("btn_instant_person"))
		{
			m_LayoutTabMettingContact->SetVisible(true);
			//m_LayoutTabMettingContact_2->SetVisible(true);
		}
		if (strName == _T("btn_appoint_person"))
		{
			m_LayoutTabMettingContact->SetVisible(true);
			//m_LayoutTabMettingContact_2->SetVisible(true);
		}
		if (strName == _T("btn_wjh"))
		{	
			// 添加到联系人列表
			m_pSelectWjhCb->SetVisible(true);
		}
		if (strName == _T("btn_fss"))
		{
			// 添加到联系人列表
			m_pSelectFssCb->SetVisible(true);
		}
		if (strName == _T("btn_lxc"))
		{	
			// 添加到联系人列表
			m_pSelectLxcCb->SetVisible(true);
		}
		if (strName == _T("btn_sks"))
		{	
			// 添加到联系人列表
			m_pSelectSksCb->SetVisible(true);
		}	
		if (strName == _T("btn_jxz"))
		{	
			// 添加到联系人列表
			m_pSelectJxzCb->SetVisible(true);
		}
		if (strName == _T("btn_contact_confirm"))
		{	
			//点击确定
			m_LayoutInstantPersonList->SetVisible(true);
			m_LayoutAppointPersonList->SetVisible(true);
			//取消选中
			m_pSelectWjhCb->SetVisible(false);
			m_pSelectFssCb->SetVisible(false);
			m_pSelectLxcCb->SetVisible(false);
			m_pSelectSksCb->SetVisible(false);
			m_pSelectJxzCb->SetVisible(false);
			m_LayoutTabMettingContact_2->SetVisible(false);
		}

		
		// 启动即时会议
		if (strName == _T("btn_start_instant"))
		{
			auto topic = m_EditInstantTopic->GetText();
			if (topic.IsEmpty())
			{
				::MessageBox(NULL, L"会议主题不能为空", L"提示", MB_OK);
				return;
			}
			const wstring& meetingTopic = m_EditInstantTopic->GetText().GetData();
			
			//会议参与人,通讯录UserId,多人已逗号分隔
			m_EditInstantPerson->SetText(L"1215111376683401216,1215111376704372736,1215111376721149952,1215111376733732864,1215111376746315776");
			const wstring& meetingParticipates = m_EditInstantPerson->GetText().GetData();

			YSXSDK::InstanceMeettingParam param;
			//CCheckBoxUI* chk = static_cast<CCheckBoxUI*>(m_pm.FindControl(L"chk_video"));
			//param.isVideoOff = chk ? !chk->GetCheck() : true;			//加入会议时是否打开视频
			param.isVideoOff = false;           //加入会议时是否打开视频
			param.isAudioOff = false;			//加入会议时是否打开音频
			param.meetingTopic = meetingTopic.c_str();				//会议主题
			param.meetingParticipants = meetingParticipates.c_str();
			//创建会议服务
			if (m_MeetingService == NULL)
			{
				if (YSX_CreateMeetingService(&m_MeetingService) == SDKError::SDKERR_SUCCESS)
				{
					if (m_MeetingService)
					{
						auto result = m_MeetingService->StartInstance(param); //开启即时会议
						if (result == SDKERR_MEETING_TOPIC_EMPTY)
						{
							::MessageBox(NULL, L"请输入会议主题", L"提示", MB_OK);
						}
						else if (result == SDKERR_TRIAL_USER_CAN_JOIN_TWICE_MEETING_EVERY_DAY)
						{
							::MessageBox(NULL, L"每天只能加入会议两次", L"试用账号", MB_OK);
						}
						else {
							//::MessageBox(NULL, m_MeetingService->GetMeetingInfo()->GetMeetingTopic(), L"提示", MB_OK);
							//m_EditInstantTopic->SetText(m_MeetingService->GetMeetingInfo()->GetMeetingHostTag());
						}
					}
					else {
						SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);  // 开启会议失败，最小化
					}
				}

			}
		}

		// 加入会议,,,,为什么失败？？ 数据格式不对，uint64需要转换
		if (strName == _T("btn_join_meeting")) {
			auto meetingNum = m_EditMeetingNumber->GetText();
			if (meetingNum.IsEmpty())
			{
				::MessageBox(NULL, L"会议号不能为空", L"提示", MB_OK);
				return;
			}
			auto str_Number = WideByte2AcsiCopy(meetingNum.GetData());
			UINT64 meetingNo = atoll(str_Number.c_str());
			
			//auto str_Number = WideByte2AcsiCopy(L"214471992");
			//auto meetingNo = atoll(str_Number.c_str());
			
			int meetingType = 0;
			YSXSDK::JoinParam param;
			param.userName = NULL;				//设置自定义名称
			param.psw = NULL;					//会议密码
			param.isVideoOff = false;			//加入会议时是否打开视频
			param.isAudioOff = false;			//打开音频
			param.meetingNumber = meetingNo;	//会议号码
			param.meetingId = L"";//会议ID,当会议是高清会议是必须填写
			param.meetingType = meetingType;	//会议类型0:多媒体,1:高清,REST API接口返回会议信息中包含会议类型,IM通知也包含会议类型

			//创建会议服务
			if (m_MeetingService == NULL)
			{
				if (YSX_CreateMeetingService(&m_MeetingService) == SDKError::SDKERR_SUCCESS)
				{
					if (m_MeetingService)
					{
						auto result = m_MeetingService->Join(param);
					}
					else {
						SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);  // 加入会议失败，最小化
					}
				}

			}
		}

		// 预约会议
		if (strName == _T("btn_appoint_meeting"))
		{
			auto topic = m_EditAppointTopic->GetText();
			if (topic.IsEmpty())
			{
				::MessageBox(NULL, L"会议主题不能为空", L"提示", MB_OK);
				return;
			}
			auto start = m_EditAppointStartTime->GetText();
			if (start.IsEmpty())
			{
				::MessageBox(NULL, L"会议开始时间不能为空", L"提示", MB_OK);
				return;
			}
			auto duration = m_EditAppointDuration->GetText();
			if (duration.IsEmpty())
			{
				::MessageBox(NULL, L"会议时长不能为空", L"提示", MB_OK);
				return;
			}
			/*
			const wstring& meetingTopic = m_EditInstantTopic->GetText().GetData();
			YSXSDK::InstanceMeettingParam param;
			//CCheckBoxUI* chk = static_cast<CCheckBoxUI*>(m_pm.FindControl(L"chk_video"));
			//param.isVideoOff = chk ? !chk->GetCheck() : true;			//加入会议时是否打开视频
			param.isVideoOff = false;           //加入会议时是否打开视频
			param.isAudioOff = false;			//加入会议时是否打开音频
			param.meetingTopic = meetingTopic.c_str();				//会议主题
			//param.meetingParticipants = L"1215111376683401216,1215111376704372736,1215111376721149952,1215111376733732864,1215111376746315776";//会议参与人,通讯录UserId,多人已逗号分隔
			param.meetingParticipants = L"";
			//创建会议服务
			if (m_MeetingService == NULL)
			{
				if (YSX_CreateMeetingService(&m_MeetingService) == SDKError::SDKERR_SUCCESS)
				{
					if (m_MeetingService)
					{
						//auto result = m_MeetingService->StartInstance(param); //预约会议
					}
					else {
						SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);  // 开启会议失败，最小化
					}
				}

			}
			*/
			
		}
	}
	__super::Notify(msg);
}



void CLoginFrame::OnClick(TNotifyUI& msg)
{
	//CDuiString pSenderName = msg.pSender->GetName();
	//::MessageBox(NULL, pSenderName, L"提示", MB_OK);

	/*

	CDuiString pSenderName = msg.pSender->GetName();
	if (pSenderName == _T("closebtn"))
	{
		PostQuitMessage(0);
	}
	else if (pSenderName == _T("minbtn"))
	{
		SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, NULL);
	}
	else if (pSenderName == _T("maxbtn"))
	{
		SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, NULL);
	}
	else if (pSenderName == _T("restorebtn"))
	{
		SendMessage(WM_SYSCOMMAND, SC_RESTORE, NULL);
	}
	else if (pSenderName == _T("loginbtn"))
	{
		CEditUI *pUsernameEdit = (CEditUI *)m_PaintManager.FindControl(_T("usernameedit"));
		CEditUI *pPasswordEdit = (CEditUI *)m_PaintManager.FindControl(_T("passwordedit"));
		pMainFrame = new CMainFrame;
		pMainFrame->Create(NULL, _T("TIM"), UI_WNDSTYLE_FRAME, WS_EX_STATICEDGE | WS_EX_APPWINDOW);
		pMainFrame->CenterWindow();
		pMainFrame->ShowWindow();
		this->ShowWindow(SW_HIDE);
	}
	else if (pSenderName == _T("cancelbtn......"))
	{
		CTabLayoutUI *pTabLayout = (CTabLayoutUI *)m_PaintManager.FindControl(_T("tab_bar"));
		CHorizontalLayoutUI *pTitleLayout = (CHorizontalLayoutUI *)m_PaintManager.FindControl(_T("title_layout"));
		pTabLayout->SelectItem(0);
		pTitleLayout->SetFixedHeight(pTitleLayout->GetHeight() + 45);
		this->m_bIsInput = FALSE;

	}
	else if (pSenderName == _T("close2btn"))
	{
		CVerticalLayoutUI *pLoginResultLayout = (CVerticalLayoutUI *)m_PaintManager.FindControl(_T("loginresult_layout"));
		pLoginResultLayout->SetVisible(false);

	}
	*/

}


LRESULT CLoginFrame::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	//return __super::OnClose(uMsg, wParam, lParam, bHandled);
	PostQuitMessage(0);
	return 0;
}
