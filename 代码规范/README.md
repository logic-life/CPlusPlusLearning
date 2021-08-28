# 文件命名
**文件名字全部要小写，中间使用_相连，然后添加后缀（.h/.cpp）**

例如：test.h/test.cpp
**************************
# 类型命名
**类型名称:类型命名的每个单词首字母必须大写，不包括下划线**

例如：MyExtensionClass,MyExcitingEnum.
*************************
# 变量命名
**不要将变量的类型在名字中体现，这样以后变量类型改变时，还需要去改变变量名，使用功能去命名，变量和数据成员名 一律小写，单词之间使用下划线连接，类的成员变量使用下划线结尾**

例如：a_local_variable,a_struct_data_member,a_class_data_member_
*************************
# 常量命名
**声明为constexpr或者const的变量或者程序运行期间其值始终保持不变的，命名时以k开头，大小写混合**

例如：const int kDaysInWeek=7;
*************************
# 函数命名
**常规函数使用大小写混合，取值和设值函数则要求与变量名匹配**

例如:MyExcitingFunction(),MyExcitingMethod(),my_exciting_member_variable(),set_my_exciting_member_variable()
*************************
# 枚举命名
**和常量一致**

例如:kErrorOut0Memory
************************
# 变量命名要意义明确，一目了然

