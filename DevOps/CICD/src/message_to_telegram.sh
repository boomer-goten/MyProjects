#!/bin/bash

TIME="10"
TEXT="CI Status:+$1%0ACD Status:+$2%0A%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0A"

curl -s "https://api.telegram.org/bot5775196844:AAHJJjgFPGwwgInCzLJVJJ14nTbRjTeMcBY/sendMessage?text=$TEXT&chat_id=1116230994" > /dev/null