// Developer: Mohammed U.
// Project: BookCatalogManagement 
// 5 files: Main.cpp, Book.cpp, Book.hpp, MoveAll.cpp, MoveAll.hpp
// Language: C++
// February 25, 2024

#include "Book.hpp"

// write and document all methods in this file.

Book::Book() {
    // string are always initialized to empty strings
    // numbers are initialized to 0
    // nullptr; When an object is moved from (i.e., its resources are transferred to another object), it's essential to leave the moved-from object in a valid state.
    title_ = "";
    author_ = "";
    ISBN_ = 0;
    icon_ = nullptr;
    price_ = 0.0;
    keywords_ = {};
    blurb_ = "";
}

// deconstructor
Book::~Book() {
    delete[] icon_; // resets 
    icon_ = nullptr;
}

// rhs = right hand side 
Book::Book(const Book& rhs) {

    // Copying title, author, ISBN, price, keywords, and blurb from rhs object
    title_ = rhs.title_;
    author_ = rhs.author_;
    ISBN_ = rhs.ISBN_;
    icon_ = new int[80]; // Allocating memory for icon data                                     
    
    // ITTERATING THROUGH ICON DATA AND COPYING IT FROM rhs object
    // Copying each element of icon array from rhs object to current object
    for (int i = 0; i < 80; ++i) {
        icon_[i] = rhs.icon_[i]; 
    }

    price_ = rhs.price_;
    keywords_ = rhs.keywords_;
    blurb_ = rhs.blurb_;
}

Book& Book::operator=(const Book& rhs) {
    if (this != &rhs) { // Check for self-assignment

        // Copying titile, author, ISBN, price, keywords, and blurb from rhs object
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;

        // -----------------------------------------------------------------|
        //                                                                    |
        //                    IMPORTANT MEMORY MANAGEMENT                     |
        //                                                                    |
        // -----------------------------------------------------------------|
        // Deleting existing icon data and allocating new memory for icon
        delete[] icon_;    
        icon_ = new int[80];    
        // ------------------------------------------------------------------|

        for (int i = 0; i < 80; ++i) {
            icon_[i] = rhs.icon_[i];
        }

        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;
    }

    return *this; // Return a reference to the current object
}

// Move Constructor
// The move constructor is used to efficiently move the resources (such as dynamically allocated memory) from the source object rhs to the current object.
// It utilizes std::move to transfer the ownership of the data members (title, author, ISBN, price, keywords, and blurb) from rhs to the current object.
// For the icon_ member, it moves the ownership of the pointer itself (not the actual data) using std::move. This means both objects will share the same dynamically allocated memory, but the ownership is transferred to the current object, and rhs.icon_ is set to nullptr to avoid memory leaks and ensure proper destruction.
// This implementation allows for efficient transfer of resources and is used in move semantics to avoid unnecessary copying of data when objects are moved.
Book::Book(Book&& rhs) {
    title_ = std::move(rhs.title_);
    author_ = std::move(rhs.author_);
    ISBN_ = std::move(rhs.ISBN_);
    icon_ = std::move(rhs.icon_);
    rhs.icon_ = nullptr;
    price_ = std::move(rhs.price_);
    keywords_ = std::move(rhs.keywords_);
    blurb_ = std::move(rhs.blurb_);
}


// Operator
// The move assignment operator is used to efficiently move the resources (such as dynamically allocated memory) from the source object rhs to the current object.
// It checks for self-assignment (this != &rhs) to avoid unnecessary work and potential issues with resource deallocation.
// It utilizes std::move to transfer the ownership of the data members (title, author, ISBN, price, keywords, and blurb) from rhs to the current object.
// For the icon_ member, it deletes the existing dynamically allocated memory, moves the ownership of the pointer itself (not the actual data) using std::move from rhs, and sets rhs.icon_ to nullptr to avoid memory leaks and ensure proper destruction.
// This implementation allows for efficient transfer of resources and is used in move semantics to avoid unnecessary copying of data when objects are moved.
Book& Book::operator=(Book&& rhs) {
    if (this != &rhs) {
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = std::move(rhs.ISBN_);
        delete[] icon_;               
        icon_ = std::move(rhs.icon_);  
        rhs.icon_ = nullptr;   
        price_ = std::move(rhs.price_);
        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);   
    }

    return *this;
}

const std::string& Book::getTitle() const {
    return title_;
}

void Book::setTitle(const std::string& title) {
    title_ = title;
}

const std::string& Book::getAuthor() const {
    return author_;
}

void Book::setAuthor(const std::string& author) {
    author_ = author;
}

long long int Book::getISBN() const {
    return ISBN_;
}

void Book::setISBN(long long int ISBN) {
    ISBN_ = ISBN;
}

const int* Book::getIcon() const {
    return icon_;
}

void Book::setIcon(int* icon) {
    icon_ = icon;
}

float Book::getPrice() const {
    return price_;
}

void Book::setPrice(float price) {
    price_ = price;
}

const std::vector<std::string>& Book::getKeywords() const {
    return keywords_;
}

void Book::setKeywords(const std::vector<std::string>& keywords) {
    keywords_ = keywords;
}

const std::string& Book::getBlurb() const {
    return blurb_;
}

void Book::setBlurb(const std::string& blurb) {
    blurb_ = blurb;
}

void Book::print() const {
    std::cout << "Title: " << title_ << std::endl;
    std::cout << "Author: " << author_ << std::endl;
    std::cout << "ISBN: " << ISBN_ << std::endl << std::endl;
    std::cout << "Icon: ";

    if (icon_ != NULL) {
        for (int i = 0; i < 80; i++) {
            std::cout << icon_[i] << " ";
        }
    }

    std::cout << std::fixed << std::setprecision(2) << std::endl << "Price: $" << price_ + 0.00 << std::endl;
    std::cout << "Keywords: ";

    for (int i = 0; i < keywords_.size(); i++) {
        // 1000 - 1 = 999; this makes sure to not print a comma after the last keyword
        if (i != keywords_.size() - 1) {
            std::cout << keywords_[i] << ", ";
        }
        else { // if it's the last keyword (greater), don't print a comma after it
            std::cout << keywords_[i];
        }
    }
    std::cout << std::endl << "Blurb: " << blurb_ << std::endl;
}
