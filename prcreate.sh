#!/bin/bash
# Create a git PR, taking a title and a URL.
# Example usage:
# ./prcreate.sh "82. Remove Duplicates from Sorted List II" https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

# Convert a string to snake case
to_snake_case() {
  local s="$1"
  # Convert to lowercase, replace non-alphanumeric characters (except underscore) with underscores
  s=$(echo "$s" | tr '[:upper:]' '[:lower:]' | sed 's/[^a-z0-9]/_/g')
  # Replace multiple underscores with a single underscore
  s=$(echo "$s" | sed 's/__*/_/g')
  # Remove leading/trailing underscores
  s=$(echo "$s" | sed 's/^_//;s/_$//')
  echo "$s"
}

TITLE="$1"
URL="$2"

# Remove /description and any trailing slashes from the URL if present
URL=$(echo "$URL" | sed 's|description[/]*$||')

# Check if a directory name was provided
if [ -z "$TITLE" ]; then
  echo "Usage: $0 <directory_name> <URL>"
  exit 1
fi

# Convert the raw input to snake case == branch name.
DIR_NAME=$(to_snake_case "$TITLE")

# Check if it's a Git repository
if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  echo "Error: Not a Git repository. Please run this script inside a Git repository."
  exit 1
fi

echo "Adding, committing, and pushing to git..."
# git push
git checkout "$DIR_NAME"
git add "$DIR_NAME"
git commit -m "$TITLE
 
$URL"
git push --set-upstream origin "$DIR_NAME"

# Create PR
echo "Creating PR..."
echo -e "# $TITLE\n\n$URL" | gh pr create \
  --base main \
  --head "$DIR_NAME" \
  --title "$TITLE" \
  --body-file=-

echo "$TITLE (Grind 75) を解いたのでレビューいただけると幸いです。"
echo "問題: $URL"
echo "PR: TBD"
echo "言語: C++"
echo "Arai 60 (Python) を C++ で解き直したものなので、個別 mention はしないでおきます。C++ レビューしてもいいよという方がいらしたらコメントいただけると嬉しいです。"
echo "また C++ を始めたばかりなので、問題のアルゴリズムよりは、C++ 言語仕様に関するコメントが多めです。多くの解き方を試すよりは、Python で書いた optimal な解法を C++ で書くとどうなるのか、といったスタンスで練習してみています。"
