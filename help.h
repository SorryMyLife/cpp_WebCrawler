//***********************************************
//*********			��������			*********
//***********************************************

#include "tool.h"
void print(std::string str)
{
	std::cout << str << std::endl;
}


int c_len(char *ch)
{
	return sizeof(ch) / sizeof(ch[0]);
}
void he()
{
	print("         Crawler [options] [usage] : \n");
	print("         -O output : ���ļ������ָ��·��(Ĭ��Ϊ��ǰ·��)\n");
	print("         -u url : URLNAME : HOST ָ��������������\n");
	print("         --no-del-tmp : not_delete_temp_file : ��ɾ�������������ʱ�ļ�(������ܵ��Գ���ʱ����,Ĭ��ɾ����ʱ�ļ�)\n");
	print("         --get-html-url : ��ȡָ�������������html����(����֤��ȫ����ȡ,Ĭ�ϲ�����)\n");
	print("         --get-img-url : ��ȡָ���������ͼƬ����(����֤��ȫ����ȡ,Ĭ�ϲ�����)\n");
	print("         -h help �г����п����õ�ѡ���Լ�˵��\n");
	print("\n			Ĭ�ϵĲ���:Crawler REGEX RE_STRING URLNAME\n\n			REGEX : ���û��ṩ���������ƥ��\n\n			RE_STRING : ���û��ṩ���˵Ĺ���\n\n			URLNAME : ���û��ṩ��Ŀ�����ӵ�ַ\n\n		���ϲ�������ȱ���κ�һ��,������ܻᵼ�³������б���");
	print("\n			���ٶ�Ҫ�����������������ϵĲ���\n");
	print("\n         �Ƽ�����: -O out_file -u url_name --get-html-url \n");
}
void er_p()
{
	print("������Crawler -h");
	exit(-1);
}
void no_p()
{
	print("���Ϸ��Ĳ����淶!");
	exit(-1);
}
