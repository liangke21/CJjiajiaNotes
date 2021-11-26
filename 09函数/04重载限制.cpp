




typedef char* PSTR;
//typedef 声明不定义新类型;它们会引入现有类型的同义词。 它们不会影响重载机制。 考虑下列代码：
void Print(char* szToPrint);
void Print(PSTR szToPrint);
//
void Print(char* szToPrint);
void Print(char szToPrint[]);
//对于多维数组，第二个和后续维度被视为类型的一部分。 因此，它们可用来区分重载函数：
void Print(char szToPrint[]);
void Print(char szToPrint[][7]);
void Print(char szToPrint[][9][42]);
