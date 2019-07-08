//
// Created by chudonghao on 19-7-8.
//

#ifndef CDH_LLVM_FRONTED_SRC_LEXER_H_
#define CDH_LLVM_FRONTED_SRC_LEXER_H_

#include <cstddef>
#include <string>

namespace cdh {

class Token {
 public:
  Token();
  virtual ~Token();
  size_t Line() { return line_; }
  size_t Pos() { return pos_; }
  void SetLine(size_t line) { line_ = line; }
  void SetPos(size_t pos) { pos_ = pos; }
 private:
  size_t line_{};
  size_t pos_{};
  std::string name_;
 public:
  const std::string &Name() const;
  void SetName(const std::string &name);
};

class OperatorToken : public Token {
 public:
  OperatorToken();
  const std::string &Name();
  void SetName(const std::string &name);
 private:
  std::string name_{};
};

class PublicToken : public Token {
 public:
  PublicToken();
};


class Lexer {
 public:
  Lexer();
  int input(char ch);
};

class GetSymbolLexer{
 public:
  GetSymbolLexer();
  int input(char ch);
  const std::string &GetErrorMessage() const;
 private:
  constexpr static size_t kBufferSize = 256;
  size_t buffer_size_{};
  char buffer_[kBufferSize];
  std::string error_message_;
  Token * last_token_{};
 public:
  Token *GetLastToken() const;
 private:
  void NewToken();
};

}
#endif //CDH_LLVM_FRONTED_SRC_LEXER_H_
