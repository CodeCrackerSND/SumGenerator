// SumGeneratorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SumGenerator.h"
#include "SumGeneratorDlg.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSumGeneratorDlg dialog

CSumGeneratorDlg::CSumGeneratorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSumGeneratorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSumGeneratorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSumGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSumGeneratorDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSumGeneratorDlg, CDialog)
	//{{AFX_MSG_MAP(CSumGeneratorDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSumGeneratorDlg message handlers

BOOL CSumGeneratorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSumGeneratorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSumGeneratorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

double* getDoubleRandNumWithSum(int n, double m, double min)
{
    double* randArray = new double[n];
    double sum = 0;

    // Generate n random numbers
    for (int i = 0; i < n; i++)
    {
        randArray[i] = rand();
        sum += randArray[i];
    }

    // check number value
    int cnt = 0;
    while (true)
    {
        if ((randArray[cnt] / sum * m) < min)  // you could try more conditions here
        {
            sum -= randArray[cnt];    
            randArray[cnt] = rand();
            sum += randArray[cnt];
            cnt = -1;
        }
    
        cnt++;
        if (cnt >= n)
        {
            break;
        }
        
    }

    // Normalize sum to m
    for (i = 0; i < n; i++)
    {
        randArray[i] /= sum;
        randArray[i] *= m;

    }

    return randArray;
}

int round(double d)
{
return static_cast<int>(d + 0.5);
}

int* getIntRandNumWithSum(int n, int i_m, int i_min)
{  // originally coded for double numbers so won't properly work for integers!

	double m = (double)i_m;  // values should be calculated as double
	double min = (double)i_min;

    int* randArray = new int[n];
    int sum = 0;

    // Generate n random numbers
    for (int i = 0; i < n; i++)
    {
        randArray[i] = rand();
        sum += randArray[i];
    }

    // check number value
    int cnt = 0;
    while (true)
    {
        if ((randArray[cnt] / sum * m) < min)  // you could try more conditions here
        {
            sum -= randArray[cnt];    
            randArray[cnt] = rand();
            sum += randArray[cnt];
            cnt = -1;
        }
    
        cnt++;
        if (cnt >= n)
        {
            break;
        }
        
    }

    // Normalize sum to m
    for (i = 0; i < n; i++)
    {
		double comp = (randArray[i]*m)/sum;  // first time we multiply else we lose value
		randArray[i] = round(comp);

    }

    return randArray;
}

int GenerateRandomInt(int range_min, int range_max)
{
// Generate random numbers in the half-closed interval  
// [range_min, range_max). In other words,  
// range_min <= random number < range_max  
int genNumb = (int)((double)rand() / (RAND_MAX + 1) * (range_max - range_min)+ range_min);
return genNumb;

}


int* getIntRandNumWithSumVer2(int n, int m, int min)
{

    int* randArray = new int[n];
	int csum = m;

	// Generate n random numbers
    for (int i = 0; i < n; i++)
    {

		if (i==n-1)  // if last number
		randArray[i] = csum;
		else
        randArray[i] = GenerateRandomInt(min, csum-((n-i-1)*min)); // GenerateRandomInt(min, max)

        csum -= randArray[i];
    }

	return randArray;
}


bool IsSumPosible(int n, int m, int min)
{
int calc_min_sum = min*n;
if (calc_min_sum<=m)  // if final sum less or equal then minim sum
return true;
else
return false;

}

bool IsSumPosible(int n, double m, double min)
{
double calc_min_sum = min*n;
if (calc_min_sum<=m)  // if final sum less or equal then minim sum
return true;
else
return false;

}


void CSumGeneratorDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	int nrOfNumbers = 0;
	char nrsStr[200];
	nrsStr[0] = 0;
	GetDlgItem(IDC_EDIT2)->GetWindowText(nrsStr, 200);

	if (nrsStr[0]!=0)
	nrOfNumbers = atoi(nrsStr);

	char sumStr[200];
	sumStr[0] = 0;
	GetDlgItem(IDC_EDIT1)->GetWindowText(sumStr, 200);

	char MinStr[200];
	MinStr[0] = 0;
	GetDlgItem(IDC_EDIT4)->GetWindowText(MinStr, 200);

	if (((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck() == 1)  // if double is checked
	{
	double sum = atof(sumStr);
	double min = atof(MinStr);

	if (!IsSumPosible(nrOfNumbers, sum, min))
	{
	GetDlgItem(IDC_EDIT3)->SetWindowText("Sum not possible!!!");
	return;
	}

	double* dnumbers = getDoubleRandNumWithSum(nrOfNumbers, sum, min);

	CString csData = "";
	CString CurData = "";

	for (int i=0;i<nrOfNumbers;i++)
	{

	CurData.Format("%lf", dnumbers[i]);

	if (i>0) csData += " ";

	csData += CurData;


	}

	GetDlgItem(IDC_EDIT3)->SetWindowText(csData);

	}
	else
	{

	int sum = atoi(sumStr);
	int min = atoi(MinStr);

	if (!IsSumPosible(nrOfNumbers, sum, min))
	{
	GetDlgItem(IDC_EDIT3)->SetWindowText("Sum not possible!!!");
	return;
	}

	int* numbers = getIntRandNumWithSumVer2(nrOfNumbers, sum, min);

	CString csData = "";
	CString CurData = "";

	for (int i=0;i<nrOfNumbers;i++)
	{

	CurData.Format("%d", numbers[i]);

	if (i>0) csData += " ";

	csData += CurData;


	}

	GetDlgItem(IDC_EDIT3)->SetWindowText(csData);
	}


}
