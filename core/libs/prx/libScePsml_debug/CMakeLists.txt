add_library(libScePsml_debug SHARED EXCLUDE_FROM_ALL Export.cpp)
target_include_directories(libScePsml_debug PRIVATE ${LIBS_INCLUDE_DIR})
configure_windows_unwind(libScePsml_debug)

if(MINGW)
    foreach(runtimeLinkFlag IN ITEMS -static-libgcc -static-libstdc++ -static)
        string(REPLACE "${runtimeLinkFlag}" "" CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
    endforeach()
endif()

if(BUILD_TESTING)
    add_test_executable(guest_psml_tests ${LIBS_INCLUDE_DIR}/tests/GuestPsml.cpp)
    target_include_directories(guest_psml_tests PRIVATE ${LIBS_INCLUDE_DIR})
    target_link_libraries(guest_psml_tests PRIVATE libScePsml_debug)
    add_test(NAME guest_psml COMMAND guest_psml_tests)

    add_test_executable(guest_psml_unimplemented_tests ${LIBS_INCLUDE_DIR}/tests/GuestPsmlUnimplemented.cpp)
    target_include_directories(guest_psml_unimplemented_tests PRIVATE ${LIBS_INCLUDE_DIR})
    target_link_libraries(guest_psml_unimplemented_tests PRIVATE libScePsml_debug)
    find_package(Python3 QUIET COMPONENTS Interpreter)
    if(Python3_Interpreter_FOUND)
        add_test(NAME guest_psml_unimplemented COMMAND ${Python3_EXECUTABLE}
                ${LIBS_INCLUDE_DIR}/tests/test_psml_unimplemented.py $<TARGET_FILE:guest_psml_unimplemented_tests>)
    endif()
    if(WIN32)
        set_tests_properties(guest_psml PROPERTIES ENVIRONMENT_MODIFICATION
            "PATH=path_list_prepend:$<TARGET_FILE_DIR:libScePsml_debug>")
        if(Python3_Interpreter_FOUND)
            set_tests_properties(guest_psml_unimplemented PROPERTIES ENVIRONMENT_MODIFICATION
                "PATH=path_list_prepend:$<TARGET_FILE_DIR:libScePsml_debug>")
        endif()
    endif()
endif()
