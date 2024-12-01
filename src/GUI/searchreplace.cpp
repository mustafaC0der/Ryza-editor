#include "searchreplace.h"
#include <QMessageBox>

SearchReplace::SearchReplace(QTextEdit *editor) : editor(editor) {
    cursor = QTextCursor(editor->document());
}

SearchReplace::~SearchReplace() {
    // Destructor (currently no dynamic allocation, but can be expanded)
}

void SearchReplace::findText(const QString &text) {
    // Search for the next occurrence of the text
    cursor = editor->document()->find(text, cursor);
    if (cursor.isNull()) {
        QMessageBox::information(editor, "Search", "Text not found.");
    } else {
        editor->setTextCursor(cursor);
    }
}

void SearchReplace::replaceText(const QString &text) {
    // Replace the current occurrence with the provided text
    if (!cursor.isNull()) {
        cursor.insertText(text);
    } else {
        QMessageBox::information(editor, "Replace", "No text selected.");
    }
}

void SearchReplace::replaceAllText(const QString &searchText, const QString &replaceText) {
    QTextCursor cursor = editor->textCursor();
    cursor.beginEditBlock();
    bool found = false;

    while (!cursor.isNull()) {
        cursor = editor->document()->find(searchText, cursor);
        if (!cursor.isNull()) {
            cursor.insertText(replaceText);
            found = true;
        }
    }

    cursor.endEditBlock();
    if (!found) {
        QMessageBox::information(editor, "Replace All", "No occurrences found.");
    }
}
