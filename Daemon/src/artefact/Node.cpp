#include "Node.h"

namespace titanic {
namespace artefact {

Node::Node(const std::string& name) : _name(name) {

}

Node::~Node() {

}

const std::string&
Node::getName() const {
	return _name;
}

bool
Node::operator<(const Node& other) const {
	return _name < other._name;
}

}
}