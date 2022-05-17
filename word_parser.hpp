#include <string.h>
#include <stdio.h>
#include <algorithm>

// Класс для работы со строкой и выводом найденных в ней строк
// Метод setString принимает указатель на массив char или ссылку на string
// Метод printWordList выводит на экран содержимое строки

class WordParser {
private:
	const char separator = ' ';
	static const int maxCharStringLength = 100;
	char str[maxCharStringLength + 2] = { '\0'};
	int stringLength = 0;

public :
	int setString(char* str) {
		memset(&this->str, '\0', sizeof(str));
		// Поиск конца строки
		int strLength = 0;
		for (; strLength < maxCharStringLength; strLength++) {
			if (str[strLength] == '\0') {
				memcpy(this->str, str, strLength);
				stringLength = strLength;
				return 0;
				break;
			}
		}
		return -1;
	};

	int setString(std::string &str) {
		std::replace(str.begin(), str.end(), '\t', ' ');
		memset(&this->str, '\0', sizeof(this->str));
		// Поиск конца строки
		stringLength = static_cast<int>(str.length());
		if (stringLength < this->maxCharStringLength) {
			strcpy_s(this->str, str.c_str());
			return 0;
		}
		return -1;
	};

	int printWordList() {
		if (stringLength > 0) {
			int lastWordBegin = 0;
			// Вывод по пробелу
			for (int i = 0; i < stringLength; i++) {
				if (this->str[i] == this->separator) {
					printWord(lastWordBegin, i - lastWordBegin);
					lastWordBegin = i + 1;
				}
			}
			// Вывод по '\0'
			printWord(lastWordBegin, stringLength - lastWordBegin);
			return 0;
		}
		return -1;

	};

private:
	int printWord(int from, const int size) {
		if (size > 0) {
			if (this->str[from] == '\t') {
				return -1;
			}

			int bufSize = size * sizeof(char);
			bufSize += 1;
			char* buf = (char*)malloc(bufSize);
			if (buf != NULL) {
				memset(buf, '\0', bufSize);
				memcpy(buf, &str[from], bufSize - (1 * sizeof(char)));
				printf("%s \r\n", const_cast<char*>(buf));
			}
			free(buf);
		}
	}
};