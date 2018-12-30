project (TCPhelp)

add_library (tcphelp tcphelp.c)

add_executable(client tcpclient.cpp)

add_executable(service tcpservice.cpp)

target_link_libraries(client tcphelp)

target_link_libraries(service tcphelp)