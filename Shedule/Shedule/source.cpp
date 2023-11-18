#include "source.hpp"


// ===== Subject =====
// mk401
// нечетная
// -- lesson --
//		421
//		13:15 - 14:45
//		Java language
//      Ivan Ivanovich Ivanov
//      Matanaliz
//      
// 
// ---- Входные данные
// group(MK401), audit(421), lesson_name(Java language), 
// week_numb(1), day_of_week(1), numb(1), start(13:15), end(14:45)



void ScheduleServer::run(string address)
{
    grpc::ServerBuilder builder;
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(this);

    std::unique_ptr<grpc::ServerCompletionQueue> cq = builder.AddCompletionQueue(); // Создание CompletionQueue через ServerBuilder
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << address << endl;

    // Обработка запросов в асинхронном режиме
    void* tag;
    bool ok;
    try
    {
        while (true) {
            if (!cq->Next(&tag, &ok)) {
                cout << "Error in forming the response!" << endl;
            }
        }
    }
    catch (std::exception& ex)
    {
        cerr << "Exception caught: " << ex.what() << endl << "The server will be stopped!" << endl;
    }

    server->Shutdown();
    cq->Shutdown();
}