# /usr/bin/python3


def main():
    i = 0
    line = input()
    end = int(line)
    print(f"counting to: {end}")
    while i < end:
        i += 1
    print(f"result: {i}")


if __name__ == "__main__":
    main()
