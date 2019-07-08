//
// Created by cdh on 19-7-8.
//

#include <fstream>
#include "Compiler.h"
#include "log.h"
#include "CompileInstance.h"
#include "Lexer.h"
using namespace std;
namespace cdh {

void Compiler::Compile(cdh::CompileInstance &instance) {
  LOG_TRACE << "开始编译" << instance.filename_;
}
Compiler::Compiler(const CompileContext &compile_context) : compile_context_(compile_context) {

}
void Compiler::GetSymbolTable(CompileInstance &instance) {
  LOG_TRACE << "获取" << instance.filename_ << "的符号表";
  GetSymbolLexer lexer;
  ifstream ifstream1(instance.filename_);
  char ch;
  while (ifstream1 >> ch) {
    if(lexer.input(ch) > 0){
      auto token = lexer.GetLastToken();
      if (token) {
        LOG_TRACE << token->Name();
      }
    }
  }
}
void Compiler::CompileAll() {

}
}
