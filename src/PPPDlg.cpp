
// PPPDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PPP.h"
#include "PPPDlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma warning( disable : 4996)
#define pi 3.1415926535897
#define gm 3.986005e14
#define block_count 407
#define we 7.2921151467e-5
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CPPPDlg 对话框



CPPPDlg::CPPPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPPPDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPPPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_COMBO2, m_hour);
	DDX_Control(pDX, IDC_COMBO3, m_minute);
	DDX_Control(pDX, IDC_COMBO4, m_sec);
	DDX_Control(pDX, IDC_X_EDIT, m_X);
	DDX_Control(pDX, IDC_Y_EDIT, m_Y);
	DDX_Control(pDX, IDC_Z_EDIT, m_Z);
}

BEGIN_MESSAGE_MAP(CPPPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_COMPUTE_BUTTON1, &CPPPDlg::OnBnClickedComputeButton1)
END_MESSAGE_MAP()


// CPPPDlg 消息处理程序

BOOL CPPPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString prn;
	for (int i = 0; i < 32; i++)
	{
		prn="";
		prn.Format(_T("%d"),i+1);
		m_combo1.AddString(prn);
	}
	CString hourStr;
	for (int i = 0; i <=24; i++)
	{
		hourStr="";
		hourStr.Format(_T("%d"),i);
		m_hour.AddString(hourStr);
	}
	CString minuteStr;
	for (int i = 0; i <60; i++)
	{
		minuteStr="";
		minuteStr.Format(_T("%d"),i);
		m_minute.AddString(minuteStr);
	}
	CString secStr;
	for (int i = 0; i < 60; i++)
	{
		secStr="";
		secStr.Format(_T("%d"),i);
		m_sec.AddString(secStr);
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPPPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPPPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPPPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


struct data
{
     int prn;
     int yer;
     int month;
     int day;
     int hour;
     int minute;
     double sec;
     double a0;
     double a1;
     double a2;
     double iode;
     double crs;
     double var_n;
     double m0;
     double cuc;
     double e;
     double cus;
     double sqrt_a;
     double t0e;
     double cic;
     double oumiga_0;
     double cis;
     double i0;
     double crc;
     double w;
     double oumiga;
     double idot;
     double codes;
     double gps_week;
     double data_flag;
     double sv_accuracy;
     double sv_health;
     double tgd;
     double iodc_issue_of_data;
     double transmission_time;
     double spare0;
     double spare1;
     double spare2;
}dt;

struct Cord
{
	double x;
	double y;
	double z;
};

double NaturalizedTime(int,int,int,int,int,int);

void CPPPDlg::OnBnClickedComputeButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Cord calculate(int,int,int,int,int);

    int prn_num;
    int differ_time;
    int t_temp;
    int near_i;
    int c_i;
    int d_h,d_m,d_s;
    FILE *fp;

	int selCur=0;
	selCur=m_combo1.GetCurSel();
	CString tempCstr;
	m_combo1.GetLBText(selCur,tempCstr);
	prn_num=_ttoi(tempCstr);
	selCur=m_hour.GetCurSel();
	m_hour.GetLBText(selCur,tempCstr);
	d_h=_ttoi(tempCstr);
	selCur=m_minute.GetCurSel();
	m_minute.GetLBText(selCur,tempCstr);
	d_m=_ttoi(tempCstr);
	selCur=m_sec.GetCurSel();
	m_sec.GetLBText(selCur,tempCstr);
	d_s=_ttoi(tempCstr);
    t_temp=7200;
    fp=fopen("E:\\GPSdata\\brdc0180.txt","r");
    if(fp==NULL)
    {
        printf("Can not open the file.\n");
        exit(1);
    }
    for(c_i=1;c_i<=block_count;c_i++)
    {
        fscanf(fp,"%d%d%d%d%d%d%lf%lf%lf%lf",&dt.prn,&dt.yer,&dt.month,&dt.day,
                &dt.hour,&dt.minute,&dt.sec,&dt.a0,&dt.a1,&dt.a2);
        fscanf(fp,"%lf%lf%lf%lf%lf%lf%lf%lf",&dt.iode,&dt.crs,&dt.var_n,&dt.m0,
                &dt.cuc,&dt.e,&dt.cus,&dt.sqrt_a);
        fscanf(fp,"%lf%lf%lf%lf%lf%lf%lf%lf",&dt.t0e,&dt.cic,&dt.oumiga_0,
                &dt.cis,&dt.i0,&dt.crc,&dt.w,&dt.oumiga);
        fscanf(fp,"%lf%lf%lf%lf%lf%lf%lf%lf",&dt.idot,&dt.codes,&dt.gps_week,
                &dt.data_flag,&dt.sv_accuracy,&dt.sv_health,&dt.tgd,&dt.iodc_issue_of_data);
        fscanf(fp,"%lf%lf%lf%lf",&dt.transmission_time,&dt.spare0,&dt.spare1,&dt.spare2);
        //find the equal number of the PRN and compare the time
        if(dt.prn==prn_num)
        {
				
            differ_time=abs((dt.hour*3600+dt.minute*60+(int)dt.sec)-(d_h*3600+d_m*60+d_s));
            if(differ_time<=t_temp)
            {
                t_temp=differ_time;
                near_i=c_i;                 /*mark the id */
            }
        }

    }
	fclose(fp);
	Cord cd=calculate(near_i,prn_num,d_h,d_m,d_s);
    CString tempStr;
	tempStr.Format(_T("%16.8lf"),cd.x);
	m_X.SetWindowTextW(tempStr);
	tempStr.Format(_T("%16.8lf"),cd.y);
	m_Y.SetWindowTextW(tempStr);
	tempStr.Format(_T("%16.8lf"),cd.z);
	m_Z.SetWindowTextW(tempStr);
    printf("All right.\n");
    putchar('\n');
    printf("please input the number of satellite(such as:3)\n");
    printf("Or input 0 to quit:");

}


Cord calculate(int k,int prn,int hh,int mm,int ss)
{
    double avg_n;
    double ms;
    double es;
    double temp;
    double fs;
    double u0;
    double correct_u;
    double correct_r;
    double correct_i;
    double u,r,i;
    double longitude;
    double X,Y,Z;
    double x,y;
    double ut;
    double tk;
    int tk_INT;
    FILE *fp;
    int gg;

    if((fp=fopen("E:\\GPSdata\\brdc0180.txt","r+"))==NULL)
    {
        printf("Can not open the file.\n");
        exit(1);
    }
    for(gg=1;gg<=k;gg++)
    {
        fscanf(fp,"%d%d%d%d%d%d%lf%lf%lf%lf",&dt.prn,&dt.yer,&dt.month,&dt.day,
               &dt.hour,&dt.minute,&dt.sec,&dt.a0,&dt.a1,&dt.a2);
        fscanf(fp,"%lf%lf%lf%lf%lf%lf%lf%lf",&dt.iode,&dt.crs,&dt.var_n,&dt.m0,
                   &dt.cuc,&dt.e,&dt.cus,&dt.sqrt_a);
        fscanf(fp,"%lf%lf%lf%lf%lf%lf%lf%lf",&dt.t0e,&dt.cic,&dt.oumiga_0,
                   &dt.cis,&dt.i0,&dt.crc,&dt.w,&dt.oumiga);
        fscanf(fp,"%lf%lf%lf%lf%lf%lf%lf%lf",&dt.idot,&dt.codes,&dt.gps_week,
                   &dt.data_flag,&dt.sv_accuracy,&dt.sv_health,&dt.tgd,&dt.iodc_issue_of_data);
        fscanf(fp,"%lf%lf%lf%lf",&dt.transmission_time,&dt.spare0,&dt.spare1,&dt.spare2);
    }
	fclose(fp);
    avg_n=pow(gm,0.5)/pow(dt.sqrt_a,3)+dt.var_n;
    tk=NaturalizedTime(dt.yer,dt.month,dt.day,hh,mm,ss);  //此时的tk为double类型，存在精度丢失
    tk_INT=(int)(tk+0.5);       //将double转成int，防止精度丢失
    ms=dt.m0+avg_n*(tk_INT);
    es=ms;
    temp=0;
    //Iteration
    do
    {
        temp=es;
        es=ms+dt.e*sin(es);
    }while(fabs(es-temp)>1e-12);
    fs=atan2(pow((1-dt.e*dt.e),0.5)*sin(es),(cos(es)-dt.e));
    u0=dt.w+fs;
    correct_u=dt.cuc*cos(2*u0)+dt.cus*sin(2*u0);
    correct_r=dt.crc*cos(2*u0)+dt.crs*sin(2*u0);
    correct_i=dt.cic*cos(2*u0)+dt.cis*sin(2*u0);
    u=u0+correct_u;
    r=dt.sqrt_a*dt.sqrt_a*(1-dt.e*cos(es))+correct_r;
    i=correct_i+dt.i0+dt.idot*(tk_INT);
    longitude=dt.oumiga_0+(dt.oumiga-we)*(tk_INT)-we*dt.t0e;
    x=r*cos(u);
    y=r*sin(u);
    X=x*cos(longitude)-y*cos(i)*sin(longitude);
    Y=x*sin(longitude)+y*cos(i)*cos(longitude);
    Z=y*sin(i);
	
	Cord cd;
	cd.x=X;
	cd.y=Y;
	cd.z=Z;
	return cd;
}

double NaturalizedTime(int y,int m,int d,int h,int minute,int s)
{
    double ut;
    double jd;
    double gpsw;
    double t;
    double temp_t;

    ut=(double)h+(double)minute/60+(double)s/3600;
    if(y>=80)
    {
        if(y==80&&m==1&&d<6)
        {
            y=y+2000;
        }
        y=y+1900;
    }
    else
    {
        y=y+2000;
    }

    if(m<=2)
    {
        y=y-1;
        m=m+12;
    }
    jd=(int)(365.25*y)+(int)(30.6001*(m+1))+d+ut/24+1720981.5;
    gpsw=(int)((jd-2444244.5)/7);
    t=(jd-2444244.5-7*gpsw)*24*3600;
    temp_t=t-dt.t0e;
    while(temp_t>302400||temp_t<-302400)
    {
        if(temp_t>302400)
            temp_t=temp_t-604800;
        else
            temp_t=temp_t+604800;
    }
    return temp_t;
}