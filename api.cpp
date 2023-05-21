
#include "api.h"
#include <filesystem>
namespace fs = std::filesystem;

// 用于储存，增删用函数实现以和 View 同步
std::set<File> FileList;
std::vector<Tag> TagList;
std::queue<int>TagScript;

std::vector<Tag*> fileshowtag(const File&)
{

}  //展示单文件标签

bool fileindir(File file)
{

}  //确认输入文件存在于目录下


Tagint taginvec(string name, string explain)
{
    //先查找，存在tag则返回其下标
	for(int i = 0; i < TagList.size(); ++i)
	{
		if(TagList[i].name==name && TagList[i].explain==explain) return i;
	}
    //不存在tag则构建一个
    Tag newtag(name,explain);
    if(!TagScript.empty()){
        TagList[TagScript.front()] = newtag;
        TagScript.pop();
    }
    else{
        TagList.push_back(newtag);
    }
    return TagList.size();
}  //确认输入tag存在于vector中,存在则返回其下标，不存在则创建并返回新的size

File* fileinset(string name, string addr)
{
    File newfile(name,addr);
    FileList.insert(newfile);
    auto itr = FileList.find(newfile);
    File* it = &(File)*itr;
    return it;
    

}  //确认输入文件存在于set中，用于给文件加标签

File* fileinvec(string name, string addr)
{
    for(int i = 0; i < TagList.size(); ++i)
	{
		for(int j = 0; j < TagList[i].T_filelist.size();++j)
        {
            if(TagList[i].T_filelist[j]->name==name&&TagList[i].T_filelist[j]->address==addr)return TagList[i].T_filelist[j];
        }
        return NULL;
	}
}  //确认输入文件存在于vector中，用于删标签




bool fileaddtag(File* file, Tag* tag)
{

}  //给文件添加标签

bool filedeltag(File* file, Tagint tagpoint)
{
    for(int i = 0; i < TagList[tagpoint].T_filelist.size(); i++)
    {
        //如果此标签里有此文件，删除并返回1，否则返回0
        if(TagList[tagpoint].T_filelist[i]->name == file->name && TagList[tagpoint].T_filelist[i]->address == file->address)
        {
            TagList[tagpoint].T_filelist.erase(TagList[tagpoint].T_filelist.begin() + i);
            return 1;
        }
    }
    return 0;
}  //给文件删除标签

bool tagdel(string name, string explain)
{

}  //删除某标签

bool tagrename(Tagint delete_tagpoint, string new_name)
{
    TagList[delete_tagpoint].name = new_name;
} //标签改名

bool tagexplain(string name, string explain)
{

}  //给标签添加说明
