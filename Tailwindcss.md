
# Setting Up Tailwind CSS in a Project 

## Prerequisites

- **VS Code**: Install the [Tailwind CSS IntelliSense extension](https://marketplace.visualstudio.com/items?itemName=bradlc.vscode-tailwindcss) to enhance the development experience with Tailwind.
- **Node.js**: Install Node.js from [here](https://nodejs.org/), if not already installed.

---

## Steps to Set Up Tailwind CSS

### 1. Install Node.js

   - Download and install Node.js from the [official website](https://nodejs.org/).
   - Verify the installation:
     ```bash
     node -v
     npm -v
     ```
   
### 2. Initialize a New Tailwind CSS Project

   - Open your project folder in **VS Code**.
   - Create the following folder structure:
     ```
     project-folder/
     ├── src/
     └── build/
     ```

### 3. Install Tailwind CSS

   - Open **PowerShell** or **Terminal** in the project folder and run:
     ```bash
     npm init -y
     npm install -D tailwindcss
     ```

### 4. Create Tailwind Configuration File

   - In the terminal, generate a Tailwind configuration file by running:
     ```bash
     npx tailwindcss init
     ```
   - This will create a `tailwind.config.js` file in your project root. You can customize this file based on your needs.

### 5. Set Up Input CSS

   - Inside the `src` folder, create a file named `input.css` and add the following code:
     ```css
     @tailwind base;
     @tailwind components;
     @tailwind utilities;
     ```

### 6. Build Tailwind CSS Output

   - Inside the `build` folder, create a folder named `css`. This is where the generated Tailwind CSS output will go.
   - Run the following command in your terminal to generate the CSS file:
     ```bash
     npx tailwindcss -i ./src/input.css -o ./build/css/style.css
     ```
   - This will generate the `style.css` file inside the `build/css` folder.

### 7. Enable Watch Mode (Optional)

   - If you want to automatically rebuild the CSS file every time you make changes, you can use the `--watch` option:
     ```bash
     npx tailwindcss -i ./src/input.css -o ./build/css/style.css --watch
     ```

---

## Folder Structure After Setup

```
project-folder/
├── src/
│   └── input.css
├── build/
│   └── css/
│       └── style.css
└── tailwind.config.js
```

---

### Screenshots for Reference

![Tailwind Setup Example](https://github.com/user-attachments/assets/3ce92d96-7407-4d8d-89d2-2158fe07815b)

![CSS Output Example](https://github.com/user-attachments/assets/4f1ce9a9-7eff-4dbc-8df7-cce20bfbe4f2)

---

## Notes

- Make sure to link the generated `style.css` in your HTML file to apply the Tailwind styles.
- You can customize the `tailwind.config.js` file to extend Tailwind's default configurations, add themes, or include additional plugins.

---

This setup allows you to efficiently use Tailwind CSS for your projects, along with live rebuilding using the `--watch` mode for faster development.

```css
/* ===== FOOTER PROTECTION FROM GLOBAL THEME OVERRIDES ===== */
/* Prevent ANY global dark theme styles from affecting the enhanced footer */

/* Override any global container/wrapper styles that might affect footer */
[data-theme='dark'] .enhanced-footer,
[data-theme='dark'] .enhanced-footer *,
[data-theme='dark'] .enhanced-footer .container,
[data-theme='dark'] .enhanced-footer .row,
[data-theme='dark'] .enhanced-footer .col,
[data-theme='dark'] .enhanced-footer div,
[data-theme='dark'] .enhanced-footer section {
  background-color: transparent !important;
}

/* Ensure footer maintains its gradient background regardless of global styles */
[data-theme='dark'] .enhanced-footer {
  background: linear-gradient(135deg, #0f0f23 0%, #1a1a2e 25%, #16213e 50%, #0f3460 75%, #533483 100%) !important;
  color: #e2e8f0 !important;
}

/* Force footer sections to maintain their intended backgrounds */
[data-theme='dark'] .enhanced-footer .footer-links-section {
  background: rgba(0, 0, 0, 0.15) !important;
}

[data-theme='dark'] .enhanced-footer .footer-bottom {
  background: rgba(0, 0, 0, 0.2) !important;
}

/* Prevent global text color overrides */
[data-theme='dark'] .enhanced-footer,
[data-theme='dark'] .enhanced-footer * {
  color: inherit !important;
}
```
815-849
