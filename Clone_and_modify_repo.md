## Make a folder and open it in VS code .
## Move to the terminal of VS code and the type the below command to clone repository.
```bash
git clone https://github.com/your-username/your-repo-name.git
```
## The link given is of the repo that needs to be cloned. For this move to your repo and simply copy the link.
## Here, I am moving the files to single folder created inside my repo
## Commands
```
mkdir contributions              # Create a new folder named 'contributions'
mv file1 file2 contributions/    # Move specified files into the new folder
git add contributions/           # Stage the changes
git commit -m "Moved files into the contributions folder"  # Commit the changes
git push origin main             # Push the changes to GitHub

```
