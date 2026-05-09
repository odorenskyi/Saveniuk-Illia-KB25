#ifndef MODULESSAVENIUK_H_INCLUDED
#define MODULESSAVENIUK_H_INCLUDED

void processSentence(const char* inputFileName, const char* outputFileName);
void appendLawArticle(const char* outputFileName);
float s_calculation(float x, float y, float z);
void appendCalculation(const char* outputFileName, float x, float y, float z, int b);

#endif // MODULESSAVENIUK_H_INCLUDED
