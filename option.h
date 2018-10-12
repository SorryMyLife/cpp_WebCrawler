//***********************************************
//*********			参数部分			*********
//***********************************************
#include "help.h"
#include <string.h>
void download_img(std::string str)
{
	mBox b;
	std::vector<std::string> v;
	v = b.getImg(str);
	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		if (i + 1 < size)
		{
			if (v[i] != v[i + 1])
			{
				print("开始下载: " + v[i]);
				b.down_file(v[i]);
				print("下载: " + v[i] + " 完成");
			}
		}
	}
}

void download_html(std::string str)
{
	mBox b;
	std::vector<std::string> v;
	v = b.getHtml(str);
	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		if (i + 1 < size)
		{
			if (v[i] != v[i + 1])
			{
				print("开始下载: " + v[i]);
				b.down_file(v[i]);
				print("下载: " + v[i] + " 完成");
			}
		}
	}
}

void download_img_no(std::string str) //顺路删除临时文件
{
	download_img(str);
	remove("tmp");
}

void download_html_no(std::string str)
{
	download_html(str);
	remove("tmp");
}

void download_img_to(std::string str ,std::string save)
{
	mBox b;
	std::vector<std::string> v;
	v = b.getImg(str);
	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		if (i + 1 < size)
		{
			if (v[i] != v[i + 1])
			{
				print("开始下载: " + v[i]);
				b.down(save,v[i]);
				print("下载: " + v[i] + " 完成");
			}
		}
	}
}

void download_html_to(std::string str , std::string save)
{
	mBox b;
	std::vector<std::string> v;
	v = b.getHtml(str);
	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		if (i + 1 < size)
		{
			if (v[i] != v[i + 1])
			{
				print("开始下载: " + v[i]);
				b.down(save,v[i]);
				print("下载: " + v[i] + " 完成");
			}
		}
	}
}

void download_img_to_no(std::string str , std::string save)
{
	download_img_to(str , save);
	remove("tmp");
}

void download_html_to_no(std::string str , std::string save)
{
	download_html_to(str,save);
	remove("tmp");
}


//定义参数的地方，毕竟对c++不熟悉，只能这样了。。。
//调用方法
//opt(argc,argv);


void opt(int as ,char *ar[])
{
	//char *url_name = "http://www.27270.com/ent/meinvtupian/";
	std::string str[] = {"-O","-u","--no-del-tmp","--get-html-url","--get-img-url","-h"};
	if (as > 1)
	{
		if (ar[1] == str[0])
		{
			if (strlen(ar[2]) > 1)
			{
				if (ar[3] == str[1])
				{
					if (strlen(ar[4]) > 1)
					{
						if (ar[5] == str[2])
						{
							if (ar[6] == str[3])
							{
								download_html_to(ar[4],ar[2]);
							}
							else if (ar[6] == str[4])
							{
								download_img_to(ar[4],ar[2]);
							}
							else
							{
								no_p();
							}
						}
						else if (ar[5] == str[3])
						{
							download_html_to_no(ar[4],ar[2]);
						}
						else if (ar[5] == str[4])
						{
							download_img_to_no(ar[4],ar[2]);
						}
						else
						{
							no_p();
						}
					}
					else
					{
						no_p();
					}
				}
				else
				{
				no_p();
				}
			}
			else
			{
				er_p();
			}
		}
		else if (ar[1] ==str[1])
		{
			if (strlen(ar[2]) > 1)
			{
				if (ar[3] == str[2])
				{
					//
					if (ar[4] == str[3])
					{
						download_html(ar[2]);
					}
					else if (ar[4] == str[4])
					{
						download_img(ar[2]);
					}
					else
					{
						no_p();
					}

				}
				else if (ar[3] == str[3])
				{
					download_html_no(ar[2]);
				}
				else if (ar[3] == str[4])
				{
					download_img_no(ar[2]);
				}
				else if (ar[3] == str[0])
				{
					if (strlen(ar[4]) > 1)
					{
						if (ar[5] == str[2])
						{
							if (ar[6] == str[3])
							{
								download_html_to_no(ar[2],ar[4]);
							}
							else if (ar[6] == str[4])
							{
								download_img_to_no(ar[2],ar[4]);
							}
							else
							{
								no_p();
							}
						}
					}
					else
					{
						er_p();
					}
				}

				else
				{
					no_p();
				}
			}
			else
			{
				er_p();
			}
		}
		else if (ar[1] == str[3])
		{
			if (ar[2] == str[0])
			{
				if (strlen(ar[3]) >1)
				{
					if (ar[4] == str[1])
					{
						if (strlen(ar[5]) >1)
						{
							download_html_to_no(ar[5],ar[3]);
						}
						else
						{
							er_p();
						}
					}
					else
					{
						no_p();
					}
				}
				else
				{
					no_p();
				}
			}
			else if (ar[2] == str[1])
			{
				if (strlen(ar[3]) > 1)
				{
					if (ar[4] == str[0])
					{
						if (strlen(ar[5]) >1)
						{
							download_html_to_no(ar[3],ar[5]);
						}
						else
						{
							no_p();
						}
					}
					else
					{
						no_p();
					}
				}
				else
				{
					no_p();
				}
			}
			else
			{
				no_p();
			}
		}
		else if (ar[1] == str[4])
		{
		if (ar[2] == str[0])
		{
			if (strlen(ar[3]) > 1)
			{
				if (ar[4] == str[1])
				{
					if (strlen(ar[5]) > 1)
					{
						download_img_to_no(ar[5],ar[3]);
					}
					else
					{
						er_p();
					}
				}
				else
				{
					no_p();
				}
			}
			else
			{
				no_p();
			}
		}
		else if (ar[2] == str[1])
		{
			if (strlen(ar[3]) > 1)
			{
				if (ar[4] == str[0])
				{
					if (strlen(ar[5]) > 1)
					{
						download_img_to_no(ar[3], ar[5]);
					}
					else
					{
						no_p();
					}
				}
				else
				{
					no_p();
				}
			}
			else
			{
				no_p();
			}
		}
		else
		{
			no_p();
		}
		}
		else if (ar[1] == str[5])
		{
			he();
		}
		else
		{
			if (strlen(ar[1]) >1)
			{
				if (strlen(ar[2]) >1)
				{
					if (strlen(ar[3]) >1)
					{
						mBox b;
						std::vector<std::string> v;
						v=b.getCustom(ar[3],ar[1],ar[2]);
						for (std::string s : v)
						{
							print(s);
						}
					}
					else
					{
						er_p();
					}
				}
				else
				{
					er_p();
				}
			}
			else
			{
				er_p();
			}
		}
	}
	else
	{
		er_p();
	}
}

