add_library(libScePsml SHARED EXCLUDE_FROM_ALL ../libScePsml_debug/Export.cpp)
target_include_directories(libScePsml PRIVATE ${LIBS_INCLUDE_DIR})
configure_windows_unwind(libScePsml)

if(BUILD_TESTING)
    add_test_executable(guest_psml_release_tests ${LIBS_INCLUDE_DIR}/tests/GuestPsml.cpp)
    target_include_directories(guest_psml_release_tests PRIVATE ${LIBS_INCLUDE_DIR})
    target_link_libraries(guest_psml_release_tests PRIVATE libScePsml)
    add_test(NAME guest_psml_release COMMAND guest_psml_release_tests)

    add_test_executable(guest_psml_release_unimplemented_tests ${LIBS_INCLUDE_DIR}/tests/GuestPsmlUnimplemented.cpp)
    target_include_directories(guest_psml_release_unimplemented_tests PRIVATE ${LIBS_INCLUDE_DIR})
    target_link_libraries(guest_psml_release_unimplemented_tests PRIVATE libScePsml)
    find_package(Python3 QUIET COMPONENTS Interpreter)
    if(Python3_Interpreter_FOUND)
        add_test(NAME guest_psml_release_unimplemented COMMAND ${Python3_EXECUTABLE}
                ${LIBS_INCLUDE_DIR}/tests/test_psml_unimplemented.py $<TARGET_FILE:guest_psml_release_unimplemented_tests>)
    endif()
    if(WIN32)
        set_tests_properties(guest_psml_release PROPERTIES ENVIRONMENT_MODIFICATION
            "PATH=path_list_prepend:$<TARGET_FILE_DIR:libScePsml>")
        if(Python3_Interpreter_FOUND)
            set_tests_properties(guest_psml_release_unimplemented PROPERTIES ENVIRONMENT_MODIFICATION
                "PATH=path_list_prepend:$<TARGET_FILE_DIR:libScePsml>")
        endif()
    endif()
endif()
