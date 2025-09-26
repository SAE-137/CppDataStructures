#include<memory>

#include"nodes/ForwardListNode.h"

//TODO : ошибка, возможная причина, старая версия c++

template<typename T>
class ForwardList
{
	std::unique_ptr<ForwardListNode<T>> m_head;
	ForwardListNode<T>* m_tail;
	size_t m_size;

public:
	ForwardList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

	~ForwardList() = default;

	ForwardListNode<T>* getHead() const { return m_head.get(); }
	ForwardListNode<T>* getTail() const { return m_tail.get(); }

	void setHead(std::unique_ptr<ForwardListNode<T>> head) { m_head = std::move(head); }
	void setTail(ForwardListNode<T> tail) { m_tail = tail; }

	bool isEmpty() const {return getHead() == nullptr;}
	size_t size() const { return m_size; }

	
	void pushBack(T value) {
		auto node = std::make_unique(ForwardListNode<T>(value));
		if (isEmpty()) {
			setHead(std::move(node));
			setTail(m_head.get());
			m_size++;
			return;
		}
		
		m_tail->setNext(std::move(node));
		setTail(m_tail->getNext());
		m_size++;
	}

	void pushFront(T value) {
		auto node = std::make_unique(ForwardListNode<T>(value));
		if (isEmpty()) {
			setHead(std::move(node));
			setTail(m_head.get());
			m_size++;
			return;
		}

		node.setNext(std::move(m_head));
		setHead(std::move(node));
		m_size++;
	}

	void clear() {
		m_head.reset();
		m_tail = nullptr;
		m_size = 0;
	}
};