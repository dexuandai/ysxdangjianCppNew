#pragma once

class CLoginFrame :
	public WindowImplBase
{
private:
	BOOL m_bIsInput = FALSE;
	//ddx
	YSXSDK::IMeetingService* m_MeetingService; 
	YSXSDK::IAuthService* m_AuthService;
	CButtonUI* m_pHomepageMinBtn = nullptr;
	CButtonUI* m_pHomepageCloseBtn = nullptr;
	//���˵�
	CButtonUI* m_pMeetingInstantBtn = nullptr;
	CButtonUI* m_pMeetingJoinBtn = nullptr;
	CButtonUI* m_pMeetingAppointBtn = nullptr;
	CButtonUI* m_pMeetingListBtn = nullptr;
	CButtonUI* m_pMeetingContactBtn = nullptr;
	//�����ʾ
	CHorizontalLayoutUI* m_LayoutSideMeetingInstant;
	CHorizontalLayoutUI* m_LayoutSideMeetingJoin;
	CHorizontalLayoutUI* m_LayoutSideMeetingAppoint;
	CHorizontalLayoutUI* m_LayoutSideMeetingList;
	CHorizontalLayoutUI* m_LayoutSideMeetingContact;
    //�Ҳ�tabҳ
	CVerticalLayoutUI* m_LayoutTabMettingInstant;
	CVerticalLayoutUI* m_LayoutTabMeetingJoin;
	CVerticalLayoutUI* m_LayoutTabMettingAppoint;
	CVerticalLayoutUI* m_LayoutTabMeetingList;
	CVerticalLayoutUI* m_LayoutTabMettingContact;
	CVerticalLayoutUI* m_LayoutTabMettingContact_1;
	CVerticalLayoutUI* m_LayoutTabMettingContact_2;
	CHorizontalLayoutUI* m_LayoutInstantPersonList;
	CHorizontalLayoutUI* m_LayoutAppointPersonList;
	//�ı���
	CEditUI* m_EditInstantTopic;
	CEditUI* m_EditInstantPerson;
	CEditUI* m_EditAppointTopic;
	CEditUI* m_EditAppointStartTime;
	CEditUI* m_EditAppointDuration;
	CEditUI* m_EditMeetingNumber;

	//���鰴ť
	CButtonUI* m_pStartInstantBtn = nullptr;
	CButtonUI* m_pJoinMeetingBtn = nullptr;
	CButtonUI* m_pAppointMeetingBtn = nullptr;
	//������ť
	CButtonUI* m_pInstantPersonBtn = nullptr;
	CButtonUI* m_pAppointPersonBtn = nullptr;
	CButtonUI* m_pTestDepartmentBtn = nullptr;
	CButtonUI* m_pTestDepartmentSelectorBtn = nullptr;
	CButtonUI* m_pSelectWjhBtn = nullptr;
	CButtonUI* m_pSelectFssBtn = nullptr;
	CButtonUI* m_pSelectLxcBtn = nullptr;
	CButtonUI* m_pSelectSksBtn = nullptr;
	CButtonUI* m_pSelectJxzBtn = nullptr;
	CButtonUI* m_pSelectConfirm = nullptr;
	//checkbox
	CControlUI* m_pSelectWjhCb = nullptr;
	CControlUI* m_pSelectFssCb = nullptr;
	CControlUI* m_pSelectLxcCb = nullptr;
	CControlUI* m_pSelectSksCb = nullptr;
	CControlUI* m_pSelectJxzCb = nullptr;

	//��ѡ��ϵ��list
	//


public:
	CLoginFrame();
	~CLoginFrame();
	virtual LPCTSTR    GetWindowClassName() const;
	virtual UINT GetClassStyle() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

	void		InitWindow();

	virtual CControlUI* CreateControl(LPCTSTR pstrClass);
	virtual LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP()
		virtual void OnClick(TNotifyUI& msg);

	//ddx
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
};