//
// Created by chudonghao on 19-7-8.
//

#include "Lexer.h"
#include "log.h"
#include "Operator.h"
using namespace std;
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
  //if (buffer_size_) {
  //  buffer_[buffer_size_] = 0;
  //  LOG_TRACE << buffer_;
  //} else {
  //  LOG_TRACE << "\\0";
  //}
  if (buffer_size_ == 0) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_') {
      current_token_type_ = kCurrentTokenTypeLetter;
    } else if ((ch >= '0' && ch <= '9')) {
      current_token_type_ = kCurrentTokenTypeNumber;
    } else if (Operator::Helper()[ch].Priority() >= 0) {
      current_token_type_ = kCurrentTokenTypeOperator;
    } else {
      current_token_type_ = kCurrentTokenTypeUnknown;
    }
    if (current_token_type_ != kCurrentTokenTypeUnknown)
      buffer_[buffer_size_++] = ch;
  } else {
    switch (current_token_type_) {
      case kCurrentTokenTypeUnknown:break;
      case kCurrentTokenTypeLetter: {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_') {
          buffer_[buffer_size_++] = ch;
        } else {
          CallOnNewToken();
          input(ch);
        }
        break;
      }
      case kCurrentTokenTypeNumber: {
        if ((ch >= '0' && ch <= '9') || ch == '.') {
          buffer_[buffer_size_++] = ch;
        } else {
          CallOnNewToken();
          input(ch);
        }
        break;
      }
      case kCurrentTokenTypeOperator: {
        const Operator *operator_ = &Operator::Helper();
        for (int i = 0; i < buffer_size_; ++i) {
          operator_ = &(*operator_)[buffer_[i]];
        }
        if ((*operator_).HasSubOperator()) {
          if ((*operator_)[ch].Priority() < 0) { //
            CallOnNewToken();
            input(ch);
          }else{
            buffer_[buffer_size_++] = ch;
          }
        } else {
          CallOnNewToken();
          input(ch);
        }
      }
    }
  }
  //
  //if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_') {
  //  buffer_[buffer_size_++] = ch;
  //} else {
  //  if (!on_getting_operator_) {
  //    CallOnNewToken();
  //    if (Operator::Helper()[ch].Priority() < 0) {
  //    } else if (!Operator::Helper()[ch].HasSubOperator()) {
  //      buffer_[buffer_size_++] = ch;
  //      CallOnNewToken();
  //    } else {
  //      buffer_[buffer_size_++] = ch;
  //      on_getting_operator_ = true;
  //    }
  //  } else {
  //    bool is_single_operator = false;
  //    char ch0 = buffer_[0];
  //    switch (ch) {
  //      case '=': {
  //        if (ch0 == '=' || ch0 == '>' || ch0 == '<' || ch0 == '!') {
  //          is_single_operator = true;
  //        }
  //        break;
  //      }
  //      case '<': {
  //        if (ch0 == '<') {
  //          is_single_operator = true;
  //        }
  //        break;
  //      }
  //      case '>': {
  //        if (ch0 == '>') {
  //          is_single_operator = true;
  //        }
  //        break;
  //      }
  //      case ':': {
  //        if (ch0 == ':') {
  //          is_single_operator = true;
  //        }
  //        break;
  //      }
  //      default:break;
  //    }
  //    if (is_single_operator) {
  //      buffer_[1] = ch;
  //      buffer_size_ = 2;
  //      CallOnNewToken();
  //    } else {
  //      CallOnNewToken();
  //      input(ch);
  //      CallOnNewToken();
  //    }
  //    on_getting_operator_ = false;
  //  }
  //  return 0;
  //}
  return 0;
}
const std::string &GetSymbolLexer::GetErrorMessage() const {
  return error_message_;
}
void GetSymbolLexer::CallOnNewToken() {
  if (buffer_size_ > 0) {
    auto token = new Token;
    buffer_[buffer_size_] = 0;
    token->SetName(buffer_);
    on_new_token_(token);
    buffer_size_ = 0;
  }
}
void GetSymbolLexer::SetOnNewToken(const std::function<void(Token *)> &on_new_token) {
  on_new_token_ = on_new_token;
}
}
