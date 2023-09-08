#include <DoopEssentials.h>

#include <TransformationSystem.h>

DataConfig SubscriptionConfigBuffer;
DataConfig SystemConfigBuffer;
TransformationSystem Transformer;

void Init()
{
    printf("Initializing...\n");

    SystemConfigBuffer.SubscriptionBuffer = &SubscriptionConfigBuffer;
    Transformer.Setup(&SystemConfigBuffer);

    printf("Initialized!\n");
}

void CleanUp()
{

}

int main()
{
    Init();

    type_info* typeCheck = Transformer.GetType();

    STR_BUILD(oss) "DataSystem:"
        << "\nValue Type: " << (typeCheck == NULL ? "Null" : typeCheck->name())
        << "\nPropertyCount: " << Transformer.PropertyCount();


    oss << SystemConfigBuffer.KeyList[0];
    
    for (int i = 0; i < Transformer.PropertyCount(); i++)
    {
        oss << "\n - " << SystemConfigBuffer.KeyList[i];
    }

    oss << "\nElementCapacity: " << Transformer.ElementCapacity()
        << "\nElementByteSize: " << Transformer.ElementByteSize()
        << "\nAllocation Size: " << Transformer.DataByteSize()
        << "\nAllocation Address: " << Transformer.DataAddress()
        << "\n";
    PRINT_F(oss)


}
