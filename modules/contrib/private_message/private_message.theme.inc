<?php

use Drupal\Core\Link;
use Drupal\Core\Url;

/**
 * Implementation of hook_preprocess_private_message_notification_block()
 */
function template_preprocess_private_message_notification_block(&$vars) {
  $vars['notification_image_path'] = base_path() . drupal_get_path('module', 'private_message') . '/images/private-message-notification-icon.png';
  $link_title = $vars['new_message_count'] ? \Drupal::service('string_translation')->formatPlural($vars['new_message_count'], 'You have 1 unread private message', 'You have @count unread private messages') : t('You have no unread private messages');
  $url = Url::fromRoute('private_message.private_message_page', [], ['attributes' => ['title' => $link_title, 'class' => ['private-message-page-link']]]);
  $count = $vars['new_message_count'] > 99 ? '99+' : $vars['new_message_count'];
  $vars['private_message_page_link'] = Link::fromTextAndUrl($count, $url)->toString();
  $vars['unread_notification_class'] = $vars['new_message_count'] ? 'unread-threads' : '';
}
