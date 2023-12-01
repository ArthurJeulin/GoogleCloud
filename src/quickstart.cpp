#include <iostream>
#include <fstream>
#include <sstream>
#include <google/cloud/storage/client.h>
#include <google/cloud/storage/oauth2/google_credentials.h>
#include "google/cloud/storage/client_options.h"


namespace gcs = google::cloud::storage;
/**
 * CAUTION TO MAKE IT WORKING YOU NEED AN AUTHENTIFICATION STEP BEFORE RUNNING
 * THIS PROGRAM.
 * INSTALL gloud CLI : https://cloud.google.com/sdk/docs/install?hl=fr
 * IN YOUR TERMINAL TYPE THE FOLLOWING COMMAND : 
 * More info : https://cloud.google.com/docs/authentication/provide-credentials-adc?hl=fr
 * gcloud auth application-default login
 * THIS WILL CREATE A CREDENTIALS FILE IN YOUR HOME REPOSITORY THAT WILL ALLOW
 * YOU TO ACCESS TO YOUR GOOGLE ACCOUNT.
*/

int main() {
    // Your code will go here
    const std::string credentials_path = "/Users/arthur/GoogleCloud/credentials/future-yeti-402810-7d20820b92fd.json";
    const std::string local_file_path = "/Users/arthur/GoogleCloud/data-to-bucket/data.txt";
    const std::string bucket_name = "save-log-file";
    const std::string object_name = "remote/file.txt";

    // Create aliases to make the code easier to read.
    namespace gcs = ::google::cloud::storage;

    // Create a client to communicate with Google Cloud Storage. This client
    // uses the default configuration for authentication and project id.
    auto client = gcs::Client();

    auto writer = client.WriteObject(bucket_name, "quickstart.txt");
    writer << "Hello World!";
    writer.Close();
    if (!writer.metadata()) {
    std::cerr << "Error creating object: " << writer.metadata().status()
            << "\n";
    return 1;
    }
    std::cout << "Successfully created object: " << *writer.metadata() << "\n";

    auto reader = client.ReadObject(bucket_name, "quickstart.txt");
    if (!reader) {
    std::cerr << "Error reading object: " << reader.status() << "\n";
    return 1;
    }

    std::string contents{std::istreambuf_iterator<char>{reader}, {}};
    std::cout << contents << "\n";


    return 0;
}
