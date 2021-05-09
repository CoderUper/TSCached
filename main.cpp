#include "storage/tsmap.h"
#include "protobuf/point.pb.h"
#include "protobuf/point.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <map>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ClientContext;
using grpc::Status;
using TSCached::QueryRequest;
using TSCached::QueryResponse;
using TSCached::WriteRequest;
using TSCached::WriteResponse;
using TSCached::TSCachedService;

using namespace std;

class Sample  final : public TSCachedService::StubInterface{
public:
    Status QueryPoints(::grpc::ClientContext *context, const QueryRequest &request,
                       ::TSCached::QueryResponse *response) override {
        response->set_message("succusful");
        return Status::OK;
    }

    Status InsertPoints(::grpc::ClientContext *context, const WriteRequest &request,
                        ::TSCached::WriteResponse *response) override {
        response->set_message("thanks");
        return Status::OK;
    }
};

void RunServer(){
    string serveraddr("0.0.0.0:5501");
    Sample s;

    ServerBuilder serverBuilder;
    serverBuilder.AddListeningPort(serveraddr,grpc::InsecureServerCredentials());
    serverBuilder.RegisterService(reinterpret_cast<grpc::Service *>(&servive));

}

int main() {
    TSCached::TSMap *tsMap = new TSCached::TSMap();
    string db = "test";
    string tableName = "tem";
    map<string,string> tags;
    tags["location"] = "SH";
    tags["owner"] = "JZG";
    TSCached::Point point(db,tableName,tags);
    for (int i = 0; i < 100; ++i) {
        TSCached::Field field;
        field.fields["item"] = i+1;
        field.fields["otem"] = i+2;
        point.Insert(field);
    }
    tsMap->Insert(point);
    TSCached::QueryPoints queryPoints(point);
    tsMap->Query(queryPoints);
    queryPoints.Print();
    return 0;
}
