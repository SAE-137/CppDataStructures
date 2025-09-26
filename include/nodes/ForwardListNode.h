#include<memory>
#include<utility>

template<typename T>
class ForwardListNode
{
	T m_value;
	std::unique_ptr<ForwardListNode<T>> m_next;

public:
	template<typename U>
	ForwardListNode(U&& value) : m_value(std::forward<U>(value)), m_next(nullptr) {}

	ForwardListNode(const ForwardListNode<T>&) = delete;
	ForwardListNode<T>& operator=(const ForwardListNode<T>&) = delete;

	ForwardListNode(ForwardListNode<T>&&) noexcept = default;
	ForwardListNode<T>& operator=(ForwardListNode<T>&&) noexcept = default;

	~ForwardListNode() = default;

	void setValue(T value) {
		m_value = value;
	}

	void setNext(std::unique_ptr<ForwardListNode<T>>&& next) {
		m_next = std::move(next);
	}

	const T& getValue() const { return m_value; }
	T& getValue() { return m_value; }

	ForwardListNode<T>* getNext() const { return m_next.get(); } 

	bool hasNext() const { return m_next != nullptr; }
};