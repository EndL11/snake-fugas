#include "BodyPart.h"

BodyPart::BodyPart() {}
BodyPart::BodyPart(Cell t_cell): m_cell(t_cell) {}
BodyPart::~BodyPart() {}
std::string BodyPart::tag() { return this->m_tag; }