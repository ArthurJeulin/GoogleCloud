# CMakeLists.txt

cmake_minimum_required(VERSION 3.26.3)
project(google-cloud-exemple)

set(CMAKE_CXX_STANDARD 17)

# Utilisez la bibliothèque client Google Cloud Storage pour C++
find_package(google_cloud_cpp_storage CONFIG REQUIRED storage)

# add_executable(send-to-bucket src/send-to-bucket.cpp)
# target_link_libraries(send-to-bucket
#                     google-cloud-cpp::storage)

# add_executable(credentials src/credentials.cpp)
# target_link_libraries(credentials
#                     google-cloud-cpp::storage)


# add_executable(test-bucket src/test-bucket.cpp)
# target_link_libraries(test-bucket
#                     google-cloud-cpp::storage)

add_executable(quickstart src/quickstart.cpp)
target_link_libraries(quickstart
                    google-cloud-cpp::storage)
