# Create product information
# [out] output_path : The path to the productinfo you created will be output.
function(create_product_info output_path)
    message("Make version information.")
    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/../cmake/productinfo.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/productinfo.h
        @ONLY
    )

    if(WIN32)
        set(${output_path} ${CMAKE_CURRENT_LIST_DIR}/../cmake/productinfo.rc PARENT_SCOPE)
    else()
        set(${output_path} "" PARENT_SCOPE)
    endif()
endfunction()
