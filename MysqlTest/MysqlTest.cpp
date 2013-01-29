// MysqlTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MysqlTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		MYSQL mysql;

		mysql_init(&mysql);

		if(!mysql_real_connect(&mysql, "localhost", "root", "root", "mydb", 3306, NULL, 0)){
			AfxMessageBox("���ݿ�����ʧ��!");
			return FALSE;
		}else{
			AfxMessageBox("���ݿ����ӳɹ�!");
		}

		char *ch_query;
		ch_query = "select * from mytable";
		if(mysql_real_query(&mysql, ch_query, strlen(ch_query)) != 0){
			AfxMessageBox("���ݿ��б�����!");
		}

		MYSQL_RES *result;
		if(!(result = mysql_use_result(&mysql))){
			AfxMessageBox("��ȡ���ݼ�ʧ��!");
		}

		MYSQL_ROW row;
		CString str;
		while (row = mysql_fetch_row(result)){
			cout << row[0] << " " << row[1] << " " << row[2] << endl;
		}

		mysql_free_result(result);


		mysql_close(&mysql);
		AfxMessageBox("�Ͽ����ݿ�����!");
	}

	getchar();
	return nRetCode;
}


