//***********************************************
//********一个适用于Linux的爬虫，用c++编写*******
//*****************支持自定义规则****************
//***********************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <regex>
#include <vector>

class mBox
{
private: std::string result = "";
public:
	std::string readFile(std::string file) //读取临时文件
	{
		std::string tmp = "";
		std::fstream f;
		f.open(file, std::ios::in);
		while (getline(f, result))
		{
			tmp += result + "\n";
		}
		result = "";
		result = tmp;
		//std::cout << result<<std::endl;
		f.close();
		return result;
	}

	void down_tmp(std::string url_name) //把网页内容存储到临时文件里面
	{
		const char* cmd = "";
		result = "wget  -O tmp ";
		result += url_name;
		cmd = result.c_str();
		system(cmd);
	}

	void down_file(std::string url_name)
	{
		const char* cmd = "";
		result = "wget ";
		result += url_name;
		cmd = result.c_str();
		system(cmd);
	}

	void down(std::string save, std::string url_name)
	{
		const char* cmd = "";
		result = "wget  -P ";
		result += save;
		result += url_name;
		cmd = result.c_str();
		system(cmd);
	}

	std::vector<std::string> search(std::string str, std::string pattern) //匹配规则
	{
		int num = 0;
		std::vector<std::string> v;
		std::regex re(pattern);
		std::smatch m;
		while (std::regex_search(str, m, re))
		{
			for (std::string s : m)
			{
				v.push_back(s);
			}
			str = m.suffix().str();
		}
		return v;

	}

	std::vector<std::string> getHtml(std::string url_name) //获取某个网站内的所有html链接
	{
		std::vector<std::string> tmp = getCustom(url_name, "href=\"(.+?\html|htm|shtml|shtm)", "href=\"");
		return tmp;
	}

	std::vector<std::string> getImg(std::string url_name) //获取某个网站内的所有图片链接
	{
		std::vector<std::string> tmp = getCustom(url_name, "<img src=\"(.+?\.jpg|png|gif)", "<img src=\"");
		return tmp;
	}

	std::vector<std::string> getCustom(std::string url_name, std::string pattern, std::string re_str) //re_str ：需要移除的内容
	{
		std::vector<std::string> v;
		std::vector<std::string> tmp;
		down_tmp(url_name);
		std::string code = readFile("tmp");
		v = search(code, pattern);
		for (std::string s : v)
		{
			if (!find_str(s, "title"))
			{
				std::string tmp_str = replace_all(s, re_str, "");
				tmp.push_back(tmp_str);
			}
			//std::cout << s << std::endl;
		}
		return tmp;
	}

	std::string replace_all(std::string str, std::string old_str, std::string new_str)
	{
		while (true)
		{
			std::string::size_type pos(0);
			if ((pos = str.find(old_str)) != std::string::npos)
			{
				str.replace(pos, old_str.length(), new_str);
			}
			else
			{
				break;
			}
		}
		return str;
	}

	bool find_str(std::string str, std::string find_s)
	{
		std::string::size_type st = str.find(find_s);
		if (st != std::string::npos)
		{
			return true;
		}
		return false;
	}

	

};
