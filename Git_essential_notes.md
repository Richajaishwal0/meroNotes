# Here, are some insights from the Udemy course on the basics of git for begineers.
# Git Basics

## Initialize a repository:
```bash
git init
```
Initialize an empty Git repository.

## Show the status of your repository:
```bash
git status
```
Displays the state of your working directory and staging area.

## Stage a specific file:
```bash
git add readme.txt
```
Stages `readme.txt` for the next commit.

## Stage all changed files:
```bash
git add .
```
Stages all changes (new, modified, or deleted files).

## Commit the staged files:
```bash
git commit -m "Create readme file"
```
Commits staged changes with a descriptive message.

## Set Notepad as the default editor:
```bash
git config --global core.editor notepad
```
Configures Notepad as the editor when no message is provided with `git commit`.

## Show the changes of a specific file:
```bash
git diff readme.txt
```
Shows changes between the working directory and the last commit for `readme.txt`.

## Show changes in your working directory:
```bash
git diff
```
Shows changes between working directory and staging area.

## Show changes in your staging area:
```bash
git diff --staged
```
Displays differences between the staging area and the latest commit.

## Show the history/log:
```bash
git log
```
Displays the commit history.

## Show the history/log with one commit per line:
```bash
git log --pretty=oneline
```
Displays each commit in a single line.

## Checkout a specific commit by its snapshot hash:
```bash
git checkout b346471
```
Checks out a commit using its unique hash.

## Navigate back to your main branch:
```bash
git checkout main
```
Switches to the main branch.

## Show the Git version:
```bash
git -v
```
Displays the current Git version.

## Show the configurations:
```bash
git config -l
```
Lists all configurations.

## Configure your username and email:
```bash
git config --global user.name "Thomas Claudius Huber"
git config --global user.email "thomas@...com"
```
Sets up the global username and email for commits.

## Show origin of configurations:
```bash
git config -l --show-origin
```
Shows where configurations are stored.

## List local branches:
```bash
git branch
```
Lists all local branches.

## Create a new branch:
```bash
git branch feature/AddTwitterHandle
```
Creates a new branch called `feature/AddTwitterHandle`.

## Checkout the new branch:
```bash
git checkout feature/AddTwitterHandle
```
Switches to the new branch.

## Merge changes into main:
```bash
git merge feature/AddTwitterHandle
```
Merges the `feature/AddTwitterHandle` branch into `main`.

## Show a graph of the history:
```bash
git log --pretty=oneline --graph
```
Displays the commit history as a graph.

## Add a remote repository:
```bash
git remote add origin https://repositoryURL
```
Adds a remote repository under the name `origin`.

## Push to the remote repository:
```bash
git push -u origin main
```
Pushes changes to the `main` branch and sets it as upstream.

## Clone a remote repository:
```bash
git clone https://repositoryURL
```
Clones a remote repository to your local machine.

## Fetch changes from the remote repository:
```bash
git fetch
```
Downloads changes from the remote without merging them.

---

Now you know the basics of Git, including how to initialize a repository, stage changes, commit, push, fetch, and branch!
