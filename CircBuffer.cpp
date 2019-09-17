#include
class CircBuffer{
public:
    CircBuffer(unsigned int size);
    void write(float input);
    float read();
private:
    std::vector buffer;
    unsigned int readIndex;
    unsigned int writeIndex;
};

CircBuffer::CircBuffer(unsigned int size) : buffer(int size){
    readIndex = 0;
    writeIndex = size - 1;
}
 
void CircBuffer::write(float input){
    buffer[writeIndex++] = input;
    if(writeIndex &gt;= buffer.size())
        writeIndex = 0;
}
 
float CircBuffer::read(){
    float val = buffer[readIndex++];
    if(readIndex &gt;= buffer.size())
        readIndex = 0;
    return val;
}