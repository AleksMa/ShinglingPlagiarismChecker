CREATE DATABASE docker;

create user docker with encrypted password 'docker';

grant all privileges on database docker to docker;

DROP TABLE IF EXISTS users CASCADE;
CREATE TABLE IF NOT EXISTS users
(
    ID        BIGSERIAL NOT NULL PRIMARY KEY,
    userName  TEXT,
    fullName  TEXT,
    studentID TEXT
);

DROP TABLE IF EXISTS tasks CASCADE;
CREATE TABLE IF NOT EXISTS tasks
(
    ID        BIGSERIAL NOT NULL PRIMARY KEY,
    taskName  TEXT,
    fullName  TEXT,
    maxTime   BIGINT,
    maxMemory BIGINT
);

DROP TABLE IF EXISTS attempts CASCADE;
CREATE TABLE IF NOT EXISTS attempts
(
    ID         BIGSERIAL NOT NULL PRIMARY KEY,
    userID     BIGINT    NOT NULL,
    taskID     BIGINT    NOT NULL,

    time       BIGINT,
    memory     BIGINT,

    sourceCode TEXT,
    uploadDate TIMESTAMP WITH TIME ZONE,

    FOREIGN KEY (userID) REFERENCES users (ID) ON DELETE CASCADE,
    FOREIGN KEY (taskID) REFERENCES tasks (ID) ON DELETE CASCADE
);

DROP TABLE IF EXISTS check_results CASCADE;
CREATE TABLE IF NOT EXISTS check_results
(
    attemptID         BIGINT NOT NULL PRIMARY KEY,
    copiedFrom        BIGINT NOT NULL,
    plagiarismPercent INT,

    FOREIGN KEY (attemptID) REFERENCES attempts (ID) ON DELETE CASCADE,
    FOREIGN KEY (copiedFrom) REFERENCES users (ID) ON DELETE CASCADE
);

DROP TABLE IF EXISTS status CASCADE;
CREATE TABLE IF NOT EXISTS status
(
    attemptID BIGINT NOT NULL PRIMARY KEY,
    status    INT,

    FOREIGN KEY (attemptID) REFERENCES attempts (ID) ON DELETE CASCADE
)



