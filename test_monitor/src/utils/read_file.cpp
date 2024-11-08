#include "utils/read_file.h"

namespace monitor {
bool ReadFile::ReadLine(std::vector<std::string>* args) {
  std::string line;
  // 将文件流中读取到的字符存到line字符串中
  std::getline(ifs_, line);
  if (ifs_.eof() || line.empty()) {
    return false;
  }
  // 创建一个输入字符串流，用line初始化它
  std::istringstream line_ss(line);
  // 从line_ss中以空格为间隔进行提取，并添加到args数组中
  // 直到字符串流的末尾，再将数组传出
  while (!line_ss.eof()) {
    std::string word;
    line_ss >> word;
    args->push_back(word);
  }
  return true;
}


}  // namespace monitor