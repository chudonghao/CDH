
find_package(Boost REQUIRED
        COMPONENTS program_options system filesystem log_setup log)
add_definitions("-DBOOST_LOG_DYN_LINK")

add_executable(llvm_frontend
        main.cpp
        Lexer.cpp
        FileContext.cpp
        FileContext.cpp
        FileContext.h
        Project.cpp
        Project.h
        CompileManager.cpp
        CompileManager.h
        log.cpp
        CompileInstance.cpp CompileInstance.h Compiler.cpp Compiler.h CompileContext.cpp CompileContext.h CompileTarget.cpp CompileTarget.h Operator.cpp Operator.h)

target_link_libraries(llvm_frontend
        ${Boost_LIBRARIES}
        pthread
        )
