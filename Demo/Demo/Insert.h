#pragma once


// Insert �Ի���

class Insert : public CDialogEx
{
	DECLARE_DYNAMIC(Insert)

public:
	Insert(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Insert();

// �Ի�������
	enum { IDD = IDD_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();
};