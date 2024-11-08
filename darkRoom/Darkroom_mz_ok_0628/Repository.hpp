#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <condition_variable>
#include <QString>
#include <QQueue>

template <class T>
class Repository
{
public:
    Repository(int t_iMaxLen);

    void AddData(T str);

    T GetData();

private:
    std::condition_variable m_Queue_Not_Empty;  //队列不满信号
    std::condition_variable m_Queue_Not_Full;       //队列不空信号
    std::mutex m_Queue_Mutex;                              //队列锁
    int m_nQueue_Max_Size;                                   //队列最大长度
    QQueue<T> m_queue;                             //队列，也可以用其他容器、或者数组
};

template<class T>
Repository<T>::Repository(int t_iMaxLen)
{
    m_nQueue_Max_Size = t_iMaxLen;
}

template<class T>
void Repository<T>::AddData(T str)
{
    std::unique_lock<std::mutex> lock(m_Queue_Mutex);
    //判断是否队列满
    while (m_queue.count() > m_nQueue_Max_Size)
    {
        //等待信号触发，阻塞在此处。此时会释放m_Queue_Mutex锁，
        //其他线程可以获取m_Queue_Mutex
        m_Queue_Not_Full.wait(lock);
    }
    m_queue.enqueue(str);
    m_Queue_Not_Empty.notify_all();
    lock.unlock(); //释放锁，也可以不调用，最后函数返回时也会释放
}

template<class T>
T Repository<T>::GetData()
{
    std::unique_lock<std::mutex> lock(m_Queue_Mutex);
    //判断是否队列满
    while (m_queue.isEmpty())
    {
        //等待信号触发，阻塞在此处。此时会释放m_Queue_Mutex锁，
        //其他线程可以获取m_Queue_Mutex
        m_Queue_Not_Empty.wait(lock);
    }
    QString str = m_queue.dequeue(); //获取数据
    m_Queue_Not_Full.notify_all();
    lock.unlock(); //释放锁，也可以不调用，最后函数返回时也会释放
    return str;
}

#endif // REPOSITORY_H
