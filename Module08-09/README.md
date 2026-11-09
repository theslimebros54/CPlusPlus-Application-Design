# Modules 8 and 9 — Video Game Library

## Module 8: Input Validation & Protecting Data

For Module 8, I added input validation to my Video Game Library application to prevent invalid information from being entered.

The program checks that game IDs are positive numbers between 1 and 9999 and that an ID is not already being used. Game titles cannot be empty or contain only spaces. Ratings must be between 0 and 10, and users must choose valid menu options.

I used `while` loops, conditional statements, and `cin.clear()` to handle incorrect inputs. When a user enters invalid information, the program displays an error message and allows them to try again. Duplicate IDs are rejected so each game has a unique identifier.

These checks help prevent incorrect data from being stored in the library.

## Module 9: Using AI to Expand My Application

### Proposed AI Feature

I chose an AI-powered video game recommendation feature. The goal is to help users discover games based on their interests.

### What the Feature Does

The user selects a preferred genre, such as RPG, Action, or Strategy. The system recommends a game from the library that matches that genre.

### What Data It Needs

The feature uses game titles, genres, ratings, and the user's selected genre. A more advanced version could also use the player's favorite games, play history, and preferences.

### What the User Sees

The user sees a recommended game and a short explanation of why it was selected.

### How AI Fits Into the Application

The C++ application would collect the user's preferences and prepare the game data. That information would be sent to an AI model, which would generate recommendations.

The application would then validate the response and display the result to the user.

**Proposed architecture:**

C++ Application → User Preferences → Prepare Game Data → AI Model → Validate Recommendation → Display Result

### Mock AI Prototype

Because I did not connect a live AI service, I created a mock recommendation feature.

The prototype compares the user's selected genre with the games stored in the library and recommends the highest-rated matching game.

This is a rule-based simulation rather than real artificial intelligence, but it demonstrates how a future AI recommendation feature could work within my application.
