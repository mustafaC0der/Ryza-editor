#ifndef SEARCHREPLACE_H
#define SEARCHREPLACE_H

#include <QTextEdit>
#include <QString>
#include <QTextCursor>

class SearchReplace {
public:
    explicit SearchReplace(QTextEdit *editor);
    ~SearchReplace();

    void findText(const QString &text);
    void replaceText(const QString &text);
    void replaceAllText(const QString &searchText, const QString &replaceText);

private:
    QTextEdit *editor;  // The text editor widget
    QTextCursor cursor; // The cursor to navigate through the editor
};

#endif // SEARCHREPLACE_H
