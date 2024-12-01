#include "mainwindow.h"
#include "searchreplace.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStatusBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Initialize UI and SearchReplace functionality
    setupUI();
    searchReplace = new SearchReplace(editor);
}

MainWindow::~MainWindow() {
    // Clean up dynamically allocated memory
    delete searchReplace;
}

void MainWindow::setupUI() {
    // Create editor
    editor = new QTextEdit(this);

    // Create search and replace input fields
    searchBar = new QLineEdit(this);
    replaceBar = new QLineEdit(this);

    // Create buttons
    findButton = new QPushButton("Find Next", this);
    replaceButton = new QPushButton("Replace", this);
    replaceAllButton = new QPushButton("Replace All", this);

    // Layout for search bar
    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchLayout->addWidget(new QLabel("Find:", this));
    searchLayout->addWidget(searchBar);
    searchLayout->addWidget(findButton);

    // Layout for replace bar
    QHBoxLayout *replaceLayout = new QHBoxLayout();
    replaceLayout->addWidget(new QLabel("Replace:", this));
    replaceLayout->addWidget(replaceBar);
    replaceLayout->addWidget(replaceButton);
    replaceLayout->addWidget(replaceAllButton);

    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(searchLayout);
    mainLayout->addLayout(replaceLayout);
    mainLayout->addWidget(editor);

    // Set central widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Connect signals to slots
    connect(findButton, &QPushButton::clicked, this, &MainWindow::findText);
    connect(replaceButton, &QPushButton::clicked, this, &MainWindow::replaceText);
    connect(replaceAllButton, &QPushButton::clicked, this, &MainWindow::replaceAllText);

    // Set a default status bar
    statusBar()->showMessage("Ready");
}

void MainWindow::findText() {
    // Call SearchReplace's findText method
    QString searchText = searchBar->text();
    searchReplace->findText(searchText);
}

void MainWindow::replaceText() {
    // Call SearchReplace's replaceText method
    QString replaceTextValue = replaceBar->text();
    searchReplace->replaceText(replaceTextValue);
}

void MainWindow::replaceAllText() {
    // Call SearchReplace's replaceAllText method
    QString searchText = searchBar->text();
    QString replaceTextValue = replaceBar->text();
    searchReplace->replaceAllText(searchText, replaceTextValue);
}

void MainWindow::show() {
    // Display the main window
    QMainWindow::show();
}
