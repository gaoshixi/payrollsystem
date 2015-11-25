
// DemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "afxdialogex.h"
#include <afx.h>
#include "MainTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDemoDlg �Ի���



CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON1, &CDemoDlg::OnBnClickedButton1)
	
END_MESSAGE_MAP()


// CDemoDlg ��Ϣ��������

BOOL CDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�
	

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ����Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDemoDlg::OnPaint()
{
	if (IsIconic())
    {
        CPaintDC dc(this); // ���ڻ��Ƶ��豸������

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // ʹͼ���ڹ����������о���
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // ����ͼ��
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        //
        // ���������ӱ���
        //
        CPaintDC dc(this);
        CRect rc;
        GetClientRect(&rc);
        CDC dcMem;
        dcMem.CreateCompatibleDC(&dc);
        CBitmap bmpBackground;
        bmpBackground.LoadBitmap(IDB_BITMAP1);

        BITMAP bitmap;
        bmpBackground.GetBitmap(&bitmap);
        CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
        dc.StretchBlt(0,0,rc.Width(), rc.Height(), &dcMem,0,0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
    }
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDemoDlg::OnBnClickedButton1()
{
	// ���ȷ����ť����֤�û����ݣ������ȷ���������棬���򵯳�����
	int state=0;//����ָʾ��֤״̬
	CString user,pwd;   //����һ��CString�������ڱ����ı���ؼ��ڵ��ı�
    
	((CEdit*)this->GetDlgItem(IDC_USERNAME))->GetWindowText(user);
	((CEdit*)this->GetDlgItem(IDC_PASSWORD))->GetWindowText(pwd);
	if(user==""||pwd=="")
	{
		::MessageBox(NULL,TEXT("�û��������벻��Ϊ��"),NULL,MB_OK);
		state=1;
		
	}
	//��ȡ�ļ�����������Ӧ�û��������Ƿ�ƥ�䣬ƥ������������棬���򵯳�����
	
	CFileFind fileFind;//�����ļ��Ƿ����
	CString strFileName1,strFileName2;
	strFileName1 = _T("../Demo/res/file/Admin.txt");
	strFileName2 = _T("../Demo/res/file/info.txt");
	if(!fileFind.FindFile(strFileName1)||!fileFind.FindFile(strFileName2))
	{
		::MessageBox(NULL,TEXT("��ȡ�û���Ϣ�ļ�ʧ��"),NULL,MB_OK);
	}

	CStdioFile file;
	if(user=="Admin")
		file.Open(strFileName1,CFile::modeRead);
	else
		file.Open(strFileName2,CFile::modeRead);
	CString strText;
	CString strTemp;
	CString user_temp,pwd_temp;//�洢���ļ��ж�ȡ�����û���Ϣ
	while(file.ReadString(strTemp))
	{
		strText += strTemp;
		//���ж�ȡ���ú��������ַ������ո�����ֱ�Ϊ�û���������
		if(AfxExtractSubString ( user_temp, strTemp, 0, ' ')&&AfxExtractSubString ( pwd_temp, strTemp, 2, ' '))
		{

			if(user==user_temp)
			{
				state=2;
				if(pwd==pwd_temp)
				{
					file.Close();
					//�رյ�¼�Ի���
					CDialog::OnOK();
					//Ȩ������
					
					//�򿪹��ʹ���ϵͳ������
					
					MainTest mdlg;
					if(user=="Admin")
					{
						mdlg.power=1;
					}
					else
					{
						mdlg.power=0;
					}
					mdlg.number=user;
					mdlg.DoModal();
				}
				else
				{
					::MessageBox(NULL,TEXT("����������������룡"),NULL,MB_OK);

				}
			}
		}
		
	}
	if(state==0)
	{
		::MessageBox(NULL,TEXT("���û������ڣ�"),NULL,MB_OK);
	}
	file.Close();
}
