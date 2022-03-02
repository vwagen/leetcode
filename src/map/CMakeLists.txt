file(GLOB files "*.cc")

foreach(file_path ${files})
    get_filename_component(file ${file_path} NAME)
    add_executable(${file}.run ${CMAKE_CURRENT_SOURCE_DIR}/${file})
    target_link_libraries(${file}.run utils)
    install(TARGETS ${file}.run
            RUNTIME DESTINATION bin)
endforeach(file_path)

