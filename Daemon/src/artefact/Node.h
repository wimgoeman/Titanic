#pragma once

#include <string>

namespace titanic {
namespace artefact {

class Node {
public:
	Node(const std::string& name);
	virtual ~Node();

	virtual const std::string& getName() const;

	virtual bool operator<(const Node& other) const;

private:
	std::string _name;

};

}
}