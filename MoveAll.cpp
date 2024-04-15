// Developer: Mohammed U.
// Project: BookCatalogManagement 
// 5 files: Main.cpp, Book.cpp, Book.hpp, MoveAll.cpp, MoveAll.hpp
// Language: C++
// February 25, 2024

#include "MoveAll.hpp"
#include "Book.hpp"

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this function.
// Use iterators whenever appropriate.
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto".

void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved=0; // counts books moved
  // DO NOT ALTER ABOVE HERE


// ------------------------------------ Implementation ------------------------------------
// The function iterates through each book in the source vector.
// For each book, it checks if the specified keyword is present in its list of keywords.
// If the keyword is found, the book is moved to the dest vector using std::move, and then erased from the source vector.
// The function records the number of books moved and measures the time taken for the operation using std::chrono.
// This function efficiently moves books based on the specified keyword and reports the number of books moved along with the time taken for the operation.
  for (int i = 0; i < source.size();) {
    bool wanted = false;

    // Check if the current book contains the specified keyword
    for (int j = 0; j < source[i].getKeywords().size(); j++) {
        if (keyword == source[i].getKeywords()[j]) {
            wanted = true;
            // break; // No need to continue checking if keyword found
        }
    }
    // If the book contains the keyword, move it to the destination vector
    if (wanted == true) {
        dest.push_back(std::move(source[i])); // Move the book to the dest vector
        books_moved++;
        source.erase(source.begin() + i); // Erase the book from the source vector
    } else {
        i = i + 1; // Move to the next book in the source vector
    }
  }

// ------------------------------------ Implementation ------------------------------------

  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}
