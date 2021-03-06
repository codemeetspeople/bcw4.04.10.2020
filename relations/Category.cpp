#include "Category.h"

Category::Category(const char* title) : title(title) {
    this->items = new std::set<Item*>();
}

Category::~Category() {
    std::set<Item*>::iterator it = this->items->begin();
    for ( ; it != this->items->end(); ++it ) {
        delete(*it);
    }
    delete(this->items);
}

const char* Category::getTitle() const {
    return this->title;
}

const std::set<Item*>& Category::getItems() const {
    return *(this->items);
}

void Category::setTitle(const char* title) {
    this->title = title;
} 

void Category::addItem(Item* item) {
    this->items->insert(item);
}

void Category::removeItem(Item* item) {
    this->items->erase(item);
}

std::ostream& operator<<(std::ostream& out, const Category& cat) {
    out << cat.getTitle() << ':' << std::endl;
    std::set<Item*>::iterator it = cat.getItems().begin();
    for ( ; it != cat.getItems().end(); ++it ) {
        out << "  --" << *(*it) << std::endl;
    }
    return out;
}