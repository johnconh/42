# Selected Requirements for the Project

_Version: 14.1_

The follwoing selection of mandatory part and modules is selected:

Requirement: Mandatory minimum of 7

Bonus 8 (+2.5):
- Five points will be awarded for each minor module.
- Ten points will be awarded for each major module

Proposed = Mandatory minimum of 7 + 6.5 -> 13.5 (we can remove 4 )

## Mandatory:

- Your website must be a **single-page application**. The user should be able to use the Back and Forward buttons of the browser.

- Your website must be compatible with the latest stable up-to-date version of **Google Chrome**.

- The user should encounter no unhandled errors and no warnings when browsing the website.

- Everything must be launched with a single command line to run an autonomous container provided by **Docker** . Example : docker-compose up --build


## Web (2.0):

- 🔎 Major module: Use a Framework as backend. _(1.0)_

  In this major module, you are required to utilize a specific web framework for your backend development, and that framework is **Django**.

- 🔎 Minor module: Use a front-end framework or toolkit. _(0.5)_

  Your frontend development will utilize the **Bootstrap toolkit**.

- 🔎 Minor module: Use a database for the backend. _(0.5)_

  The designated database for all DB instances in your project is **PostgreSQL**.
  This choice guarantees data consistency and compatibility across all project components and may be a prerequisite for other modules, such as the backend Framework module.

## User Management (2.0):

This module delves into the realm of User Management, addressing crucial aspects of user interactions and access control within the Pong platform. It encompasses two major components, each focused on essential elements of user management and authentication: user participation across multiple tournaments and the implementation of remote authentication.

- 🔎 Major module: Standard user management, authentication, users across tournaments. _(1.0)_

  - Users can subscribe to the website in a secure way.
  - Registered users can log in in a secure way.
  - Users can select a unique display name to play the tournaments.
  - Users can update their information.
  - Users can upload an avatar, with a default option if none is provided.
  - Users can add others as friends and view their online status.
  - User profiles display stats, such as wins and losses.
  - Each user has a Match History including 1v1 games, dates, and relevant details, accessible to logged-in users.
  - Duplicate usernames/emailsare not allowed.

- 🔎 Major module: Implementing a remote authentication. _(1.0)_

  In this major module, the goal is to implement the following authentication system:
  **OAuth 2.0 authentication with 42**. Key features and objectives include:

  - Integrate the authentication system, allowing users to securely sign in.
  - Obtain the necessary credentials and permissions from the authority to enable a secure login.
  - Implement user-friendly login and authorization flows that adhere to best practices and security standards.
  - Ensure the secure exchange of authentication tokens and user information between the web application and the authentication provider.

## Gameplay and user experience (3.5):

The main purpose of this website is to play Pong versus other players:

- Users must have the ability to participate in a live Pong game against another player directly on the website. Both players will use the same keyboard. _(0.0)_

- 🔎 Major module: Remote players. _(1.0)_
  The Remote players module enhance the functionality described above with remote players.
  It is possible to have two distant players. Each player is located on a separated computer, accessing the same website and playing the same Pong game. Think about network issues, like unexpected disconnection or lag. You have to offer the best user experience possible.

- Two game modes are required: _(0.0)_

  - Arcade mode (player vs. player): A player must be able to play against another player. _(0.0)_
  - Tournament mode:
    - A player must be able to launch a tournament.
    - This tournament will consist of multiple players who can take turns playing against each other.
    - At the start of a tournament, each player must register their user.
    - There must be a matchmaking system: the tournament system organize the matchmaking of the participants, and announce the next fight.
    - You have flexibility in how you implement the tournament, but it must clearly display who is playing against whom and the order of the players.

- All players must adhere to the same rules, which includes having identical paddle speed. _(0.0)_

- The visual aesthetics can vary, it must still capture the essence of the original Pong (1972) _(0.0)_

- 🔎 Major module: Multiplayers (more than 2 in the same game). _(1.0)_

	It is possible to have more than two players. Each player needs a live control (so the previous “Distant players” module is highly recommanded). It’s up to you to define how the game could be played with 3, 4, 5, 6 ... players. Along with the regular 2 players game, you can choose a single number of players, greater than 2, for this multiplayer module. Ex: 4 players can play on a squarred board, each player owns one unique side of the square.

- 🔎 Minor module: Game Customization Options. _(0.5)_

	In this minor module, the goal is to provide customization options for all available games on the platform. Key features and objectives include:

	- Offer customization features, such as power-ups, attacks, or different maps, that enhance the gameplay experience.
	- Allow users to choose a default version of the game with basic features if they prefer a simpler experience.
	- Ensure that customization options are available and applicable to all games offered on the platform.
	- Implement user-friendly settings menus or interfaces for adjusting game parameters.
	- Maintain consistency in customization features across all games to provide a unified user experience.

	This module aims to give users the flexibility to tailor their gaming experience across all available games by providing a variety of customization options while also offering a default version for those who prefer a straightforward gameplay experience.

- 🔎 Major module: Live chat. _(1.0)_

	You have to create a chat for your users in this module:

	- The user should be able to send direct messages to other users.
	- The user should be able to block other users. This way, they will see no more messages from the account they blocked.
	- The user should be able to invite other users to play a Pong game through the chat interface.
	- The tournament system should be able to warn users expected for the next game.
	- The user should be able to access other players profiles through the chat interface.


## AI-Algo _(0.5)_

- 🔎 Minor module: User and Game Stats Dashboards. _(0.5)_

	In this minor module, the goal is to introduce dashboards that display statistics for individual users and game sessions. Key features and objectives include:

	- Create user-friendly dashboards that provide users with insights into their own gaming statistics.
	- Develop a separate dashboard for game sessions, showing detailed statistics, outcomes, and historical data for each match.
	- Ensure that the dashboards offer an intuitive and informative user interface for tracking and analyzing data.
	- Implement data visualization techniques, such as charts and graphs, to present statistics in a clear and visually appealing manner.
	- Allow users to access and explore their own gaming history and performance metrics conveniently.
	- Feel free to add any metrics you deem useful.

	This minor module aims to empower users with the ability to monitor their gaming statistics and game session details through user-friendly dashboards, providing a comprehensive view of their gaming experience.

## Cybersecurity _(1.0)_

In order to create a basic functional website, here are a few security concerns that you have to tackle:
- Any password stored in your database, if applicable, must be hashed.
- Your website must be protected against SQL injections/XSS.
- If you have a backend or any other features, it is mandatory to enable an HTTPS connection for all aspects (Utilize wss instead of ws...).
- You must implement some form of validation for forms and any user input, either within the base page if no backend is used or on the server side if a backend is employed.

Please make sure you use a strong password hashing algorithm.

For obvious security reasons, any credentials, API keys, env variables etc... must be saved locally in a .env file and ignored by git. Publicly stored credentials will lead you directly to a failure of the project.

- 🔎 Major module: Implement Two-Factor Authentication (2FA) and JWT. _(1.0)_

	In this major module, the goal is to enhance security and user authentication by introducing Two-Factor Authentication (2FA) and utilizing JSON Web Tokens (JWT). Key features and objectives include:

	- Implement Two-Factor Authentication (2FA) as an additional layer of security for user accounts, requiring users to provide a secondary verification method, such as a one-time code, in addition to their password.
	- Utilize JSON Web Tokens (JWT) as a secure method for authentication and authorization, ensuring that user sessions and access to resources are managed securely.
	- Provide a user-friendly setup process for enabling 2FA, with options for SMS codes, authenticator apps, or email-based verification.
	- Ensure that JWT tokens are issued and validated securely to prevent unauthorized access to user accounts and sensitive data.

	This major module aims to strengthen user account security by offering Two-Factor Authentication (2FA) and enhancing authentication and authorization through the use of JSON Web Tokens (JWT).

## Accessibility (2.5)

- 🔎 Minor module: Support on all devices. _(0.5)_

	In this module, the main focus is to ensure that your website works seamlessly on all types of devices. Key features and objectives include:
	- Make sure the website is responsive, adapting to different screen sizes and orientations, ensuring a consistent user experience on desktops, laptops, tablets, and smartphones.
	- Ensure that users can easily navigate and interact with the website using different input methods, such as touchscreens, keyboards, and mice, depending on the device they are using.

	This module aims to provide a consistent and user-friendly experience on all devices, maximizing accessibility and user satisfaction.

- 🔎 Minor module: Expanding Browser Compatibility. _(0.5)_

	In this minor module, the objective is to enhance the compatibility of the web 	application by adding support for an additional web browser. Key features and objectives include:

	- Extend browser support to include an additional web browser, ensuring that users can access and use the application seamlessly.
	- Conduct thorough testing and optimization to ensure that the web application functions correctly and displays correctly in the newly supported browser.
	- Address any compatibility issues or rendering discrepancies that may arise in the added web browser.
	- Ensure a consistent user experience across all supported browsers, maintaining usability and functionality.

	This minor module aims to broaden the accessibility of the web application by supporting an additional web browser, providing users with more choices for their browsing experience.

- 🔎 Minor module: Multiple language supports. _(0.5)_

	In this minor module, the objective is to ensure that your website supports multiple languages to cater to a diverse user base. Key features and goals include:

	- Implement support for a minimum of three languages on the website to accommodate a broad audience.
	- Provide a language switcher or selector that allows users to easily change the website’s language based on their preferences.
	- Translate essential website content, such as navigation menus, headings, and key information, into the supported languages.
	- Ensure that users can navigate and interact with the website seamlessly, regardless of the selected language.
	- Consider using language packs or localization libraries to simplify the translation process and maintain consistency across different languages.
	- Allow users to set their preferred language as a default choice for subsequent visits to the website.

	This minor module aims to enhance the accessibility and inclusivity of your website by offering content in multiple languages, making it more user-friendly for a diverse international audience.

- 🔎 Minor module: Server-Side Rendering (SSR) Integration. _(0.5)_

  - It is possible to have more than two players.
  - Each player needs a live control (so the previous “Distant players” module is highly recommanded).
  - It’s up to you to define how the game could be played with 3, 4, 5, 6 ... players.
  - Along with the regular 2 players game, you can choose a single number of players, greater than 2, for this multiplayer module. Ex: 4 players can play on a squarred board, each player owns one unique side of the square.

- Minor module: Game Customization Options. _(0.5)_

  In this minor module, the goal is to provide customization options for all available games on the platform. Key features and objectives include:

  - Offer customization features, such as power-ups, attacks, or different maps, that enhance the gameplay experience.
  - Allow users to choose a default version of the game with basic features if they prefer a simpler experience.
  - Ensure that customization options are available and applicable to all games offered on the platform.
  - Implement user-friendly settings menus or interfaces for adjusting game parameters.
  - Maintain consistency in customization features across all games to provide a unified user experience.

- Major module: Live chat. _(1.0)_

  - The user should be able to send direct messages to other users.
  - The user should be able to block other users. This way, they will see no more messages from the account they blocked.
  - The user should be able to invite other users to play a Pong game through the chat interface.
  - The tournament system should be able to warn users expected for the next game.
  - The user should be able to access other players profiles through the chat interface.

### AI-Algo _(0.5)_

- Minor module: User and Game Stats Dashboards. _(0.5)_ **<-- en duda!!**

  In this minor module, the goal is to introduce dashboards that display statistics for individual users and game sessions. Key features and objectives include:

  - Create user-friendly dashboards that provide users with insights into their own gaming statistics.
  - Develop a separate dashboard for game sessions, showing detailed statistics, outcomes, and historical data for each match.
  - Ensure that the dashboards offer an intuitive and informative user interface for tracking and analyzing data.
  - Implement data visualization techniques, such as charts and graphs, to present statistics in a clear and visually appealing manner.
  - Allow users to access and explore their own gaming history and performance metrics conveniently.
  - Feel free to add any metrics you deem useful.

- 🔎 Major module: Replacing Basic Pong with Server-Side Pong and Implementing an API. _(1.0)_

- Mandatory:

  In order to create a basic functional website, here are a few security concerns that you have to tackle:

  - Any password stored in your database, if applicable, must be hashed.
  - Please make sure you use a strong password hashing algorithm.
  - Your website must be protected against SQL injections/XSS.
  - If you have a backend or any other features, it is mandatory to enable an HTTPS connection for all aspects (Utilize wss instead of ws...).
  - You must implement some form of validation for forms and any user input, either within the base page if no backend is used or on the server side if a backend is employed.
  - For obvious security reasons, any credentials, API keys, env variables etc... must be saved locally in a .env file and ignored by git. Publicly stored credentials will lead you directly to a failure
    of the project.

	- Develop server-side logic for the Pong game to handle gameplay, ball movement, scoring, and player interactions.
	- Create an API that exposes the necessary resources and endpoints to interact with the Pong game, allowing partial usage of the game via the Command-Line Interface (CLI) and web interface.
	- Design and implement the API endpoints to support game initialization, player controls, and game state updates.
	- Ensure that the server-side Pong game is responsive, providing an engaging and enjoyable gaming experience.
	- Integrate the server-side Pong game with the web application, allowing users to play the game directly on the website.

  In this major module, the goal is to enhance security and user authentication by introducing Two-Factor Authentication (2FA) and utilizing JSON Web Tokens (JWT). Key features and objectives include:

  - Implement Two-Factor Authentication (2FA) as an additional layer of security for user accounts, requiring users to provide a secondary verification method, such as a one-time code, in addition to their password.

  - Utilize JSON Web Tokens (JWT) as a secure method for authentication and authorization, ensuring that user sessions and access to resources are managed securely.

  - Provide a user-friendly setup process for enabling 2FA, with options for SMS codes, authenticator apps, or email-based verification.

  - Ensure that JWT tokens are issued and validated securely to prevent unauthorized access to user accounts and sensitive data.

### Accessibility (2.5)

- 🔎 Major module: Enabling Pong Gameplay via CLI against Web Users with API Integration. _(1.0)_

	In this major module, the goal is to develop a Command-Line Interface (CLI) that allows users to play Pong against players using the web version of the game. The CLI should connect to the web application seamlessly, enabling CLI users to join and interact with web players. Key features and objectives include:
	- Create a robust CLI application that replicates the Pong gameplay experience available on the website, providing CLI users with the ability to initiate and participate in Pong matches.
	- Utilize the API to establish communication between the CLI and the web application, enabling CLI users to connect to the site and interact with web players.
	- Develop a user authentication mechanism within the CLI, allowing CLI users to log in to the web application securely.
	- Implement real-time synchronization between the CLI and web users, ensuring that gameplay interactions are seamless and consistent.
	- Enable CLI users to join and create Pong matches with web players, facilitating cross-platform gameplay.
	- Provide comprehensive documentation and guidance on how to use the CLI effectively for Pong matches against web users.

	This major module aims to enhance the Pong gaming experience by creating a CLI that seamlessly connects CLI users to web players through API integration, offering a unified and interactive gameplay environment.