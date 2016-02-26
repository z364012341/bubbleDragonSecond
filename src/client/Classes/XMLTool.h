//*******************************************************************************
//类名称   : CXXX
//功能     : <本项目解析,修改,创建xml>
//-------------------------------------------------------------------------------
//备注     : <解析xml文件>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _XML_TOOL_H_
#define _XML_TOOL_H_
#include <string>
namespace bubble_second {
    class StageDataModule;
    class XMLTool
    {
    public:
        XMLTool();
        ~XMLTool();
    public:
        //获取关卡配置信息
        StageDataModule* decodeStageXMLWithStageNumble(int stageNumble);
        int convertStringToInt(const std::string& str);

    };
}
#endif //_XML_TOOL_H_