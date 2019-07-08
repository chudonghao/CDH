//
// Created by chudonghao on 19-7-8.
//

#include "Lexer.h"
namespace cdh {

Token::Token() {

}
Token::~Token() {

}
const std::string &Token::Name() const {
  return name_;
}
void Token::SetName(const std::string &name) {
  name_ = name;
}
OperatorToken::OperatorToken() {

}
const std::string &OperatorToken::Name() {
  return name_;
}
void OperatorToken::SetName(const std::string &name) {
  name_ = name;
}
PublicToken::PublicToken() {

}
Lexer::Lexer() {

}
int Lexer::input(char ch) {
  return 0;
}
GetSymbolLexer::GetSymbolLexer() {

}

int GetSymbolLexer::input(char ch) {
  if (buffer_size_ >= kBufferSize) {
    error_message_ = "缓冲区溢出";
    return -1;
  }
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_') {
    buffer_[buffer_size_++] = ch;
    return 0;
  }

//  if ((ch >= '!' && ch <= '_') || (ch >= 'a' && ch <= '~')) {// 空白符之外的所有可用字符
  if (ch == ' ') {
    NewToken();
  } else if (ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}') {
    NewToken();
    buffer_[buffer_size_++] = ch;
  } else if (buffer_size_ == 1) {
    bool is_binary_operator = false;
    char ch0 = buffer_[0];
    switch (ch) {
      case '=': {
        if (ch0 == '=' || ch0 == '>' || ch0 == '<' || ch0 == '!') {
          is_binary_operator = true;
        }
        break;
      }
      case '<': {
        if (ch0 == '<') {
          is_binary_operator = true;
        }
        break;
      }
      case '>': {
        if (ch0 == '>') {
          is_binary_operator = true;
        }
        break;
      }
      case ':': {
        if (ch0 == ':') {
          is_binary_operator = true;
        }
        break;
      }
    }
    if (is_binary_operator) {
      buffer_[1] = ch;
      NewToken();
    } else {
      NewToken();
      buffer_[buffer_size_++] = ch;
    }
  }
  return last_token_ ? 1 : 0;
}
const std::string &GetSymbolLexer::GetErrorMessage() const {
  return error_message_;
}
void GetSymbolLexer::NewToken() {
  if (buffer_size_) {
    if (last_token_)
      delete last_token_;
    last_token_ = new Token;
    buffer_[buffer_size_] = 0;
    last_token_->SetName(buffer_);
    buffer_size_ = 0;
  } else {
    last_token_ = nullptr;
  }
}
Token *GetSymbolLexer::GetLastToken() const {
  return last_token_;
}
}
