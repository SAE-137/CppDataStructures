#include<memory>
#include<utility>

template<typename T>
class ForwardListNode
{
	T m_value;
	std::unique_ptr<ForwardListNode> m_next;

public:
	template<typename U>
	ForwardListNode(U&& value) : m_value(std::forward<U>(value), m_next(nullptr) {}

	~ForwardListNode() = default;

	void setValue(T value) {
		m_value = value;
	}

	void setNext(std::unique_ptr<ForwardListNode>&& next) {
		m_next = std::move(next);
	}

	const T& getValue() const { return m_value; }
	T& getValue() { return m_value; }

	std::unique_ptr<ForwardListNode> getNext() const { return m_next.get(); }

	bool hasNext() const { return m_next != nullptr; }
};