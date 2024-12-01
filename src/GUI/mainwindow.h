#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include "searchreplace.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void show();

private slots:
    void findText();
    void replaceText();
    void replaceAllText();

private:
    void setupUI();

    QTextEdit *editor;           // Text editor widget
    QLineEdit *searchBar;        // Search text input field
    QLineEdit *replaceBar;       // Replace text input field
    QPushButton *findButton;     // Button for "Find Next"
    QPushButton *replaceButton;  // Button for "Replace"
    QPushButton *replaceAllButton; // Button for "Replace All"

    SearchReplace *searchReplace; // Object to handle Search and Replace functionality
};

#endif // MAINWINDOW_H
